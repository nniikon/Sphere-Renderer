#include "tgp_image.h"

using namespace TGP;

ImageRect::ImageRect(const sf::Sprite& sprite)
    : sprite_(sprite) {}

int ImageRect::Draw(sf::RenderWindow* window) {
    window->draw(sprite_);
    return 0;
}
