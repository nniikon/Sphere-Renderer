#include "sphere_renderer.h"
#include "tgp_window.h"
#include "sphere_buttons.h"

#include <cassert>
#include <cmath>

using namespace Sphere;
using namespace TGP;

const unsigned int kWindowWidth  = 800u;
const unsigned int kWindowHeight = 800u;
const unsigned int kButtonWidth  = 160u;
const unsigned int kButtonHeight = 160u;

int main() {
    TGP::Window window{kWindowWidth + kButtonWidth,
                       kWindowHeight, "Sphere Render"};

    Sphere::Renderer renderer{kWindowWidth, kWindowHeight,
                              vec3<float>{400.f, 400.f, 400.f}, 250u,
                              vec3<float>{350.f, 350.f, 800.f}};

    sf::Texture texture{};
    if (texture.loadFromFile("textures/buttons.png") != true) {
        assert(0);
        return 1;
    }

    sf::Sprite button_sprite      (texture, sf::Rect( 16,   0,  16,  16));
    sf::Sprite button_sprite_hover(texture, sf::Rect( 16,  48,  16,  16));
    button_sprite      .scale(10.f, 10.f);
    button_sprite_hover.scale(10.f, 10.f);

    LinearTransition linear_transition{};
    window.GetButtonManager()->AddObject(std::make_unique<ButtonAddLightSource>(
                                                button_sprite,
                                                button_sprite_hover, &renderer,
                                                vec3<float>{250.f, 150.f, 0.f},
                                                vec3<float>{ 0.3f,  0.3f, 1.0f},
                                                linear_transition));

    SinTransition sin_transition{};
    button_sprite      .move(0u, 160u);
    button_sprite_hover.move(0u, 160u);
    window.GetButtonManager()->AddObject(std::make_unique<ButtonAddLightSource>(
                                                button_sprite,
                                                button_sprite_hover, &renderer,
                                                vec3<float>{850.f, 850.f, 750.f},
                                                vec3<float>{1.0f, 0.3f, 0.3f},
                                                sin_transition));

    EaseOutTransition ease_out_transition{};
    button_sprite      .move(0u, 160u);
    button_sprite_hover.move(0u, 160u);
    window.GetButtonManager()->AddObject(std::make_unique<ButtonAddLightSource>(
                                                button_sprite,
                                                button_sprite_hover, &renderer,
                                                vec3<float>{150.f, 750.f, 650.f},
                                                vec3<float>{0.3f, 1.0f, 0.3f},
                                                ease_out_transition));

    EaseInOutTransition ease_in_out_transition{};
    button_sprite      .move(0u, 160u);
    button_sprite_hover.move(0u, 160u);
    window.GetButtonManager()->AddObject(std::make_unique<ButtonAddLightSource>(
                                                button_sprite,
                                                button_sprite_hover, &renderer,
                                                vec3<float>{450.f, 150.f, 950.f},
                                                vec3<float>{0.3f, 0.3f, 1.0f},
                                                ease_in_out_transition));

    DumpTransition dump_transition{};
    button_sprite      .move(0u, 160u);
    button_sprite_hover.move(0u, 160u);
    window.GetButtonManager()->AddObject(std::make_unique<ButtonAddLightSource>(
                                                button_sprite,
                                                button_sprite_hover, &renderer,
                                                vec3<float>{550.f, 050.f, 050.f},
                                                vec3<float>{0.3f, 0.3f, 1.0f},
                                                dump_transition));

    window.GetPixelAreaManager()->AddObject(std::make_unique<TGP::PixelArea>(renderer.GetImage(),
                                                                             vec2u({kButtonWidth,            0u}),
                                                                             vec2u({kWindowWidth, kWindowHeight})));

    while (window.IsOpen()) {
        window.Update();
        window.Draw();
    }

}
