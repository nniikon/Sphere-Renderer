#ifndef TGP_IMAGE_MANAGER_H_
#define TGP_IMAGE_MANAGER_H_

#include "tgp_manager.h"
#include "tgp_image.h"

#include <SFML/Window/Event.hpp>

namespace TGP {

class ImageManager : public ManagerBase<ImageBase>, Drawable {
public:
    void Draw(sf::RenderWindow* window) override;

    ImageManager()  = default;
    ~ImageManager();
};

} // namespace TGP

#endif // TGP_IMAGE_MANAGER_H_

