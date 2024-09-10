#include "sphere_window.h"

#include <cstring>
#include <iostream>
#include <cassert>

using namespace TGP;

Window::Window(unsigned int width, unsigned height, const char* window_name) 
    : window_width_ (width),
      window_height_(height),
      window_(sf::VideoMode(width, height), window_name),
      pixel_areas_(){
}

Window::~Window() {
    for (std::unique_ptr<PixelArea>& area : pixel_areas_) {
        PixelArea* ptr = area.release();
        delete[] ptr->pixels_;
        delete ptr;
    }
}

bool Window::IsWindowOpen() {
    return window_.isOpen();
}

void Window::Update() {
    window_.clear();

    // TODO: add support for multiple events per frame
    event_ = {};
    sf::Event event{};
    while (window_.pollEvent(event)) {
        event_ = HandleEvents(event);
    }

    DrawPixelAreas();
    DrawButtonElements();

    window_.display();
}

Window::ElementLocation Window::CreateElementLocation(unsigned int x,     unsigned int y,
                                                      unsigned int width, unsigned int height) {
    return ElementLocation{.x_      = x,
                           .y_      = y,
                           .width_  = width,
                           .height_ = height};
}

size_t Window::CreatePixelArea(unsigned int x,     unsigned int y,
                               unsigned int width, unsigned int height) {
    std::unique_ptr<PixelArea> area = std::make_unique<PixelArea>();

    area->location_ = CreateElementLocation(x, y, width, height);
    
    area->pixels_ = new sf::Uint8[width * height * kChannelsPerPixel];
    std::memset(area->pixels_, 125, width * height * kChannelsPerPixel);

    area->texture_.create(width, height);
    area->sprite_.setTexture(area->texture_);
    area->sprite_.setPosition(static_cast<float>(x),
                              static_cast<float>(y));

    pixel_areas_.push_back(std::move(area));

    return pixel_areas_.size() - 1;
}

void Window::UpdatePixelArea(size_t area_index, const vec3<uint8_t>* pixels) {
    PixelArea& area = *pixel_areas_[area_index];
    for (unsigned int i = 0; i < area.location_.width_ * area.location_.height_; i++) {
        area.pixels_[kChannelsPerPixel * i + 0] = pixels[i].r;
        area.pixels_[kChannelsPerPixel * i + 1] = pixels[i].g;
        area.pixels_[kChannelsPerPixel * i + 2] = pixels[i].b;
        area.pixels_[kChannelsPerPixel * i + 3] = 255;
    }
}

void Window::DrawPixelAreas() {
    for (std::unique_ptr<PixelArea>& area : pixel_areas_) {
        area->texture_.update(area->pixels_);
        window_.draw(area->sprite_);
    }
}

size_t Window::CreateButtonElement(unsigned int x,     unsigned int y,
                                   unsigned int width, unsigned int height,
                                   const char* file_path) {
    std::unique_ptr<ButtonElement> button = std::make_unique<ButtonElement>();

    button->location_ = CreateElementLocation(x, y, width, height);
    button->texture_.loadFromFile(file_path, sf::IntRect{(int)0, (int)0, (int)width, (int)height});
    button->sprite_.setTexture(button->texture_);
    button->sprite_.setPosition(static_cast<float>(x), 
                                static_cast<float>(y));

    button_elements_.push_back(std::move(button));

    return button_elements_.size() - 1;
}

void Window::DrawButtonElements() {
    for (std::unique_ptr<ButtonElement>& button : button_elements_) {
        window_.draw(button->sprite_);
    }
}

Event Window::HandleEvents(const sf::Event& event) {
    switch (event.type)
    {
        case sf::Event::Closed:              return HandleWindowClosed();
        case sf::Event::MouseButtonPressed:  return HandleMouseEvent(true);
        case sf::Event::MouseButtonReleased: return HandleMouseEvent(false);

        case sf::Event::MouseMoved:
        case sf::Event::KeyReleased:
        case sf::Event::Resized:
        case sf::Event::KeyPressed:
        case sf::Event::LostFocus:
        case sf::Event::GainedFocus:
        case sf::Event::TextEntered:
        case sf::Event::MouseWheelMoved:
        case sf::Event::MouseWheelScrolled:
        case sf::Event::MouseEntered:
        case sf::Event::MouseLeft:
        case sf::Event::JoystickButtonPressed:
        case sf::Event::JoystickButtonReleased:
        case sf::Event::JoystickMoved:
        case sf::Event::JoystickConnected:
        case sf::Event::JoystickDisconnected:
        case sf::Event::TouchBegan:
        case sf::Event::TouchMoved:
        case sf::Event::TouchEnded:
        case sf::Event::SensorChanged:
        case sf::Event::Count:
        default:
            return {.type = EventType::TiananmenSquareMassacre1989};
            break;
    }
}

Event Window::HandleMouseEvent(bool is_pressed) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window_);
    for (size_t i = 0; i < button_elements_.size(); i++) {
        const std::unique_ptr<ButtonElement>& button = button_elements_[i];

        ElementLocation location = button->location_;

        if (location.x_ <= mouse_pos.x && mouse_pos.x <= location.x_ + location.width_ &&
            location.y_ <= mouse_pos.y && mouse_pos.y <= location.y_ + location.height_) {

            EventType event_type = is_pressed ? EventType::PressedButton 
                                              : EventType::ReleasedButton;
            return { .type = event_type,
                     .button_event= { .x = mouse_pos.x,
                                      .y = mouse_pos.y,
                                      .button_index = i } };
        }
    }
    return { .type = EventType::TiananmenSquareMassacre1989 };
}

Event Window::HandleWindowClosed() {
    window_.close();
    return { .type = EventType::Closed };
}

const Event& Window::GetLastEvent() {
    return event_;
}
