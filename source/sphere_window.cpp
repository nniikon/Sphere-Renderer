#include "sphere_window.h"

#include <cstring>

Window::Window(unsigned int width, unsigned height, const char* window_name) 
    : window_width_ (width),
      window_height_(height),
      pixels_(new sf::Uint8[width * height * kChanelsPerPixel]),
      window_(sf::VideoMode(width, height), window_name) {

    memset(pixels_, 255, width * height * kChanelsPerPixel * sizeof(sf::Uint8));
    texture_.create(width, height);
    sprite_ = sf::Sprite(texture_);
}

Window::~Window() {
    delete[] pixels_;
    pixels_ = nullptr;
}


bool Window::IsWindowOpen() {
    return window_.isOpen();
}


void Window::Update() {
    texture_.update(pixels_);
    window_.clear();
    window_.draw(sprite_);
    window_.display();

    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window_.close();
    }
}


void Window::Update(const vec3<uint8_t>* pixels) {
    for (unsigned int i = 0; i < window_width_ * window_height_; i++) {
        pixels_[kChanelsPerPixel * i + 0] = pixels[i].r;
        pixels_[kChanelsPerPixel * i + 1] = pixels[i].g;
        pixels_[kChanelsPerPixel * i + 2] = pixels[i].b;
        pixels_[kChanelsPerPixel * i + 3] = 255;
    }
    Update();
}
