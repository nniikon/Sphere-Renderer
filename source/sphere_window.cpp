#include "sphere_window.h"

#include <cstring>
#include <iostream>
#include <cassert>

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

    DrawPixelAreas();

    sf::Event event{};
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window_.close();
    }
}

void Window::DrawPixelAreas() {
    for (std::unique_ptr<PixelArea>& area : pixel_areas_) {
        area->texture_.update(area->pixels_);
        window_.draw(area->sprite_);
        window_.display();
    }
}

size_t Window::CreatePixelArea(unsigned int x,     unsigned int y,
                               unsigned int width, unsigned int height) {

    std::unique_ptr<PixelArea> area = std::make_unique<PixelArea>();
    area->x_ = x;
    area->y_ = y;
    area->width_  = width;
    area->height_ = height;
    
    area->pixels_ = new sf::Uint8[width * height * kChannelsPerPixel];
    std::memset(area->pixels_, 125, width * height * kChannelsPerPixel);
    
    area->texture_.create(width, height);
    area->sprite_.setTexture(area->texture_);
    area->sprite_.setPosition(static_cast<float>(x),
                              static_cast<float>(y));

    pixel_areas_.push_back(std::move(area));

    return 0;
}

void Window::UpdatePixelArea(size_t area_index, const vec3<uint8_t>* pixels) {
    
    PixelArea& area = *pixel_areas_[area_index];
    for (unsigned int i = 0; i < area.width_ * area.height_; i++) {
        area.pixels_[kChannelsPerPixel * i + 0] = pixels[i].r;
        area.pixels_[kChannelsPerPixel * i + 1] = pixels[i].g;
        area.pixels_[kChannelsPerPixel * i + 2] = pixels[i].b;
        area.pixels_[kChannelsPerPixel * i + 3] = 255;
    }
}
