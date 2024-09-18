#include "tgp_pixel_area.h"

using namespace TGP;

PixelArea::PixelArea(const vec3<uint8_t>* user_pixels,
                     const vec2u pos,
                     const vec2u size)
    : user_pixels_(user_pixels),
      pos_        (pos),
      size_       (size),
      pixels_(size.x * size.y * kChannelsPerPixel),
      texture_(){

    texture_.create(size_.x, size_.y);
}

void PixelArea::Draw(sf::RenderWindow* window) {

    for (unsigned int i = 0; i < size_.x * size_.y; i++) {
        pixels_[kChannelsPerPixel * i + 0] = user_pixels_[i].r;
        pixels_[kChannelsPerPixel * i + 1] = user_pixels_[i].g;
        pixels_[kChannelsPerPixel * i + 2] = user_pixels_[i].b;
        pixels_[kChannelsPerPixel * i + 3] = 255;
    }

    texture_.update(pixels_.data());
    sprite_.setTexture(texture_);
    sprite_.setPosition((float)pos_.x, 
                        (float)pos_.y);

    window->draw(sprite_);
}
