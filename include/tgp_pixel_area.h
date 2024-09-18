#ifndef TGP_PIXEL_AREA_H_
#define TGP_PIXEL_AREA_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "tgp_manager.h"
#include "tgp_vectors.h"

namespace TGP {

class PixelArea: public Drawable {
public:
    const unsigned int kChannelsPerPixel = 4u;

    const vec3<uint8_t>* user_pixels_;
    const vec2u          pos_;
    const vec2u          size_;

    void Draw(sf::RenderWindow* window) override;

    PixelArea(const vec3<uint8_t>* image,
              const vec2u          pos,
              const vec2u          size); 

    virtual ~PixelArea() = default;

private:
    std::vector<sf::Uint8> pixels_;
    sf::Texture texture_;
    sf::Sprite  sprite_;
};

} // namespace

#endif // TGP_PIXEL_AREA_H_
