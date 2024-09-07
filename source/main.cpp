#include "sphere_renderer.h"
#include "sphere_window.h"

const unsigned int WINDOW_WIDTH  = 800u;
const unsigned int WINDOW_HEIGHT = 800u;

int main() {
    Window window{WINDOW_WIDTH, WINDOW_HEIGHT, "Sphere Render"};
    Sphere::Renderer renderer{};

    renderer.AddLightSource({850.f, 850.f, 750.f}, {1.0f, 0.0f, 0.0f});
    renderer.AddLightSource({150.f, 750.f, 650.f}, {0.0f, 1.0f, 0.0f});
    renderer.AddLightSource({450.f, 150.f, 950.f}, {0.0f, 0.0f, 1.0f});

    renderer.Render();
    const vec3<uint8_t>* pixels = renderer.GetImage();

    while(window.IsWindowOpen()) {
        window.Update(pixels);
    }
}
