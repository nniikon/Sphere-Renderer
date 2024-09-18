#ifndef TGP_PIXEL_AREA_MANAGER_H_
#define TGP_PIXEL_AREA_MANAGER_H_

#include "tgp_manager.h"
#include "tgp_pixel_area.h"

#include <SFML/Window/Event.hpp>

namespace TGP {

class PixelAreaManager : public ManagerBase<PixelArea>, Drawable {
public:
    void Draw(sf::RenderWindow* window) override;

    PixelAreaManager()  = default;
    ~PixelAreaManager() = default;
};

}; // namespace

#endif // TGP_PIXEL_AREA_MANAGER_H_
