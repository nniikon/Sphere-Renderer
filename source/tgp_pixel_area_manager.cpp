#include "tgp_pixel_area_manager.h"

using namespace TGP;


void PixelAreaManager::Draw(sf::RenderWindow* window) {
    for (size_t i = 0; i < Size(); i++) {
        PixelArea* area = Get(i);
        area->Draw(window);
    }
}
