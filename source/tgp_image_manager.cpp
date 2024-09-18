#include "tgp_image_manager.h"

using namespace TGP;

ImageManager::~ImageManager() {
}

void ImageManager::Draw(sf::RenderWindow* window) {
    for (size_t i = 0; i < Size(); i++) {
        ImageBase* button = Get(i);
        button->Draw(window);
    }
}
