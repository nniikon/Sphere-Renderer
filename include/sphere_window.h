#ifndef SPHERE_WINDOW_H_
#define SPHERE_WINDOW_H_

#include <memory>
#include <SFML/Graphics.hpp>
#include "vec.h"

using namespace Vectors;

namespace TGP {

enum class EventType {
    TiananmenSquareMassacre1989 = 0, // nothing happened
    Closed = 1,
    //  PressedLMB,
    //  PressedRMB,
    //  ReleasedLMB,
    //  ReleasedRMB,
    PressedButton,
    ReleasedButton,
};

struct ButtonEvent {
    int x;
    int y;
    size_t button_index;
};

struct Event {
    EventType type;
    union {
        ButtonEvent button_event;
    };
};

class Window {
private:
    const unsigned int window_width_;
    const unsigned int window_height_;
    const unsigned int kChannelsPerPixel = 4u;

    sf::RenderWindow window_;
    Event event_;


    struct ElementLocation {
        unsigned int x_      = 0u;
        unsigned int y_      = 0u;
        unsigned int width_  = 0u;
        unsigned int height_ = 0u;
    };
    ElementLocation CreateElementLocation(unsigned int x,     unsigned int y,
                                          unsigned int width, unsigned int height);

    struct PixelArea {
        sf::Uint8* pixels_ = nullptr;
        sf::Texture texture_;
        sf::Sprite sprite_;
        ElementLocation location_;
    };

    struct ButtonElement {
        const char* file_path_ = nullptr;
        sf::Texture texture_;
        sf::Sprite sprite_;
        ElementLocation location_;
    };

    std::vector<std::unique_ptr<PixelArea>>     pixel_areas_;
    std::vector<std::unique_ptr<ButtonElement>> button_elements_;

    Event HandleWindowClosed();
    Event HandleMouseEvent(bool is_pressed);
    Event HandleEvents(const sf::Event& event);

    void DrawPixelAreas();
    void DrawButtonElements();

public:

    bool IsWindowOpen();
    void Update();
    size_t CreatePixelArea    (unsigned int x,     unsigned int y,
                               unsigned int width, unsigned int height);
    void UpdatePixelArea(size_t area_index, const vec3<uint8_t>* pixels);

    size_t CreateButtonElement(unsigned int x,     unsigned int y,
                               unsigned int width, unsigned int height,
                               const char* file_path);
    const Event& GetLastEvent();


    Window(unsigned int width, unsigned height, const char* window_name);
    ~Window();
    Window           (const Window&) = delete;
    Window& operator=(const Window&) = delete;
};

}; // namespace

#endif // SPHERE_WINDOW_H_
