#ifndef TGP_IMAGE_H_
#define TGP_IMAGE_H_

#include <SFML/Graphics.hpp>

namespace TGP {

class ImageBase {
public:
    virtual int Draw(sf::RenderWindow* window) = 0;
    virtual ~ImageBase() = default;
};

class ImageRect : public ImageBase {
public:
    int Draw(sf::RenderWindow* window) override;

    ImageRect(const sf::Sprite& sprite);
    ~ImageRect() override = default;

private:
    sf::Sprite sprite_;
};

} // namespace TGP

#endif // TGP_IMAGE_H_

