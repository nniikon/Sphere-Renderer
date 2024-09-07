#ifndef SPHERE_WINDOW_H_
#define SPHERE_WINDOW_H_

#include <SFML/Graphics.hpp>
#include "vec.h"

using namespace Vectors;

class Window {
private:
    const unsigned int window_width_;
    const unsigned int window_height_;
    const unsigned int kChanelsPerPixel = 4u;
    sf::Uint8* pixels_ = nullptr;
    sf::Texture texture_;
    sf::Sprite  sprite_;
    sf::RenderWindow window_;
public:
    bool IsWindowOpen();
    void Update();
    void Update(const vec3<uint8_t>* pixels);
    Window(unsigned int width, unsigned height, const char* window_name);
    ~Window();
};

#endif // SPHERE_WINDOW_H_
