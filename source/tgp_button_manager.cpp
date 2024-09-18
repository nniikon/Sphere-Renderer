#include "tgp_button_manager.h"

using namespace TGP;

ButtonManager::~ButtonManager() {}

void ButtonManager::Draw(sf::RenderWindow* window) {
    for (size_t i = 0; i < Size(); i++) {
        ButtonBase* button = Get(i);
        button->Draw(window);
    }
}

void ButtonManager::Update(const sf::Event& event, const sf::RenderWindow& window) {
    sf::Vector2i mouse_pos_i = sf::Mouse::getPosition(window);
    vec2f mouse_pos_f{static_cast<float>(mouse_pos_i.x),
                      static_cast<float>(mouse_pos_i.y)};

    for (size_t i = 0; i < Size(); i++) {
        ButtonBase* button = Get(i);
        UpdateButton(button, event, mouse_pos_f);
    }

}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch-enum"
void ButtonManager::UpdateButton(ButtonBase* button, const sf::Event& event, const vec2f& mouse_pos_f) {
    if (!button->DoesIntersect(mouse_pos_f)) {
        button->OnIdle();
        return;
    }

    switch (event.type) {
        case sf::Event::MouseButtonPressed:  button->OnPress  (); break;
        case sf::Event::MouseButtonReleased: button->OnRelease(); break;
        default:                             button->OnHover  (); break;
    }
}
#pragma GCC diagnostic pop
