#include "sphere_renderer.h"
#include "sphere_window.h"

#include <cmath>

const unsigned int WINDOW_WIDTH    = 800u;
const unsigned int WINDOW_HEIGHT   = 800u;
const unsigned int ROTATION_RADIUS = 350u;

int main() {
    Window window{WINDOW_WIDTH, WINDOW_HEIGHT, "Sphere Render"};
    Sphere::Renderer renderer{WINDOW_WIDTH, WINDOW_HEIGHT,
                              vec3<float>{400.f, 400.f, 400.f}, 300u,
                              vec3<float>{350.f, 350.f, 800.f}};

    renderer.AddLightSource({850.f, 850.f, 750.f}, {1.0f, 0.3f, 0.3f});
    // renderer.AddLightSource({150.f, 750.f, 650.f}, {0.3f, 1.0f, 0.3f});
    // renderer.AddLightSource({450.f, 150.f, 950.f}, {0.3f, 0.3f, 1.0f});


    float angle = 0.f;
    while(window.IsWindowOpen()) {
        renderer.SetLightSource(0,
                                vec3<float>{ 400.f,
                                             400.f + ROTATION_RADIUS * sinf(angle),
                                             400.f + ROTATION_RADIUS * cosf(angle)},
                                {1.0f, 0.3f, 0.3f});

        renderer.Render();
        window.Update(renderer.GetImage());
        angle += 0.01f;
    }
}
