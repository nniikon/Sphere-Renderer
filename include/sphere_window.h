#ifndef SPHERE_WINDOW_H_
#define SPHERE_WINDOW_H_

#include <memory>
#include <SFML/Graphics.hpp>
#include "vec.h"

using namespace Vectors;

class Window {
private:
    const unsigned int window_width_;
    const unsigned int window_height_;
    const unsigned int kChannelsPerPixel = 4u;

    sf::RenderWindow window_;

    struct PixelArea {
        sf::Uint8* pixels_ = nullptr;
        sf::Texture texture_;
        sf::Sprite sprite_;
        unsigned int x_      = 0u;
        unsigned int y_      = 0u;
        unsigned int width_  = 0u;
        unsigned int height_ = 0u;
    };
    std::vector<std::unique_ptr<PixelArea>> pixel_areas_;

    void DrawPixelAreas();

public:
    bool IsWindowOpen();
    void Update();
    size_t CreatePixelArea(unsigned int x,     unsigned int y,
                           unsigned int width, unsigned int height);

    void UpdatePixelArea(size_t area_index, const vec3<uint8_t>* pixels);

    Window(unsigned int width, unsigned height, const char* window_name);
    ~Window();
    Window           (const Window&) = delete;
    Window& operator=(const Window&) = delete;
};

#endif // SPHERE_WINDOW_H_
