#include "sphere_renderer.h"
#include "sphere_window.h"

#include <cmath>
#include <iostream>

const unsigned int WINDOW_WIDTH    = 800u;
const unsigned int WINDOW_HEIGHT   = 800u;
const unsigned int ROTATION_RADIUS = 350u;

int main() {
    Window window{WINDOW_WIDTH, WINDOW_HEIGHT, "Sphere Render"};
    size_t pixel_area_index = window.CreatePixelArea(0u, 0u, WINDOW_WIDTH, WINDOW_HEIGHT);

    Sphere::Renderer renderer{WINDOW_WIDTH, WINDOW_HEIGHT,
                              vec3<float>{400.f, 400.f, 400.f}, 200u,
                              vec3<float>{350.f, 350.f, 800.f}};

    renderer.AddLightSource({850.f, 850.f, 750.f}, {1.0f, 0.3f, 0.3f});
    renderer.AddLightSource({150.f, 750.f, 650.f}, {0.3f, 1.0f, 0.3f});
    renderer.AddLightSource({450.f, 150.f, 950.f}, {0.3f, 0.3f, 1.0f});
    renderer.AddLightSource({550.f, 050.f, 050.f}, {0.3f, 0.3f, 1.0f});
    renderer.AddLightSource({250.f, 150.f, 000.f}, {0.3f, 0.3f, 1.0f});

    std::cerr << pixel_area_index << std::endl;
    while(window.IsWindowOpen()) {
        renderer.Render();
        window.UpdatePixelArea(pixel_area_index, renderer.GetImage());
        window.Update();
    }
}
