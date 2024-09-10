// main cringe
#include "sphere_renderer.h"
#include "sphere_window.h"

#include <cmath>
#include <iostream>

const unsigned int WINDOW_WIDTH    = 800u;
const unsigned int WINDOW_HEIGHT   = 800u;
const unsigned int BUTTON_SIZE     = 348u;
const unsigned int ROTATION_RADIUS = 350u;

int main() {
    TGP::Window window{WINDOW_WIDTH + BUTTON_SIZE, WINDOW_HEIGHT + BUTTON_SIZE, "Sphere Render"};
    size_t pixel_area_index = window.CreatePixelArea(0u, 0u, WINDOW_WIDTH, WINDOW_HEIGHT);
    size_t button_index1    = window.CreateButtonElement(WINDOW_WIDTH, 0 * BUTTON_SIZE, BUTTON_SIZE, BUTTON_SIZE, "/home/nniikon/Projects/SphereRenderer/textures/button.png");
    size_t button_index2    = window.CreateButtonElement(WINDOW_WIDTH, 1 * BUTTON_SIZE, BUTTON_SIZE, BUTTON_SIZE, "/home/nniikon/Projects/SphereRenderer/textures/button.png");
    size_t button_index3    = window.CreateButtonElement(WINDOW_WIDTH, 2 * BUTTON_SIZE, BUTTON_SIZE, BUTTON_SIZE, "/home/nniikon/Projects/SphereRenderer/textures/button.png");
    size_t button_index4    = window.CreateButtonElement(WINDOW_WIDTH, 3 * BUTTON_SIZE, BUTTON_SIZE, BUTTON_SIZE, "/home/nniikon/Projects/SphereRenderer/textures/button.png");

    std::cerr << pixel_area_index << std::endl;

    Sphere::Renderer renderer{WINDOW_WIDTH, WINDOW_HEIGHT,
                              vec3<float>{400.f, 400.f, 400.f}, 250u,
                              vec3<float>{350.f, 350.f, 800.f}};

    renderer.AddLightSource({250.f, 150.f, 000.f}, {0.3f, 0.3f, 1.0f});


    while(window.IsWindowOpen()) {
        renderer.Render();
        window.UpdatePixelArea(pixel_area_index, renderer.GetImage());

        const TGP::Event& event = window.GetLastEvent();
        size_t button_index = -1ul;
        switch (event.type) {
            case TGP::EventType::PressedButton: 
                std::cout << "Pressed  button " << event.button_event.button_index << " at pos (" << event.button_event.x << ", " << event.button_event.y << ")\n";
                button_index = event.button_event.button_index;
                break;
            case TGP::EventType::ReleasedButton:
                std::cout << "Released button " << event.button_event.button_index << " at pos (" << event.button_event.x << ", " << event.button_event.y << ")\n";
                button_index = event.button_event.button_index;
                break;
            case TGP::EventType::TiananmenSquareMassacre1989:
            case TGP::EventType::Closed:
            default:
                break;
        }

        if (button_index == button_index1 && event.type == TGP::EventType::ReleasedButton) renderer.AddLightSource({850.f, 850.f, 750.f}, {1.0f, 0.3f, 0.3f});
        if (button_index == button_index2 && event.type == TGP::EventType::ReleasedButton) renderer.AddLightSource({150.f, 750.f, 650.f}, {0.3f, 1.0f, 0.3f});
        if (button_index == button_index3 && event.type == TGP::EventType::ReleasedButton) renderer.AddLightSource({450.f, 150.f, 950.f}, {0.3f, 0.3f, 1.0f});
        if (button_index == button_index4 && event.type == TGP::EventType::ReleasedButton) renderer.AddLightSource({550.f, 050.f, 050.f}, {0.3f, 0.3f, 1.0f});

        window.Update();
    }
}
