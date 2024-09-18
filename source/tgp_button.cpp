#include "tgp_button.h"

using namespace TGP;

bool ButtonRectBase::DoesIntersect(vec2f pos) {
    sf::FloatRect rect = sprite_.getGlobalBounds();

    return (rect.contains(pos.x, pos.y));
}

void ButtonRectBase::Draw(sf::RenderWindow* window) {
    window->draw(sprite_);
}

ButtonRectBase::ButtonRectBase(const sf::Sprite& sprite)
    : sprite_(sprite) {}

//============================| ButtonRectTest |===============================

#include <iostream>

ButtonRectTest::ButtonRectTest(const sf::Sprite& sprite)
    : ButtonRectBase(sprite) {}

void ButtonRectTest::some_function() {
    std::cout << "Some function uses some data\n";
    std::cout << "Here's a string: <" << some_str << ">\n";
    std::cout << "Here's an integer: <" << some_integer << ">\n";
}

void ButtonRectTest::OnHover(){
    std::cout << "Hover the test button\n";
}

void ButtonRectTest::OnIdle(){
    std::cout << "Idle the test button\n";
}

void ButtonRectTest::OnPress(){
    std::cout << "Press the test button\n";

    some_function();
}

void ButtonRectTest::OnRelease() {
    std::cout << "Release the test button\n";

    some_function();
}

//===========================| ButtonRectInteractive |=============================

ButtonRectInteractive::ButtonRectInteractive(const sf::Sprite& sprite,
                                             const sf::Sprite& sprite_hover)
    : ButtonRectBase(sprite),
      is_hovered_(false),
      sprite_hover_(sprite_hover) {}

void ButtonRectInteractive::OnHover(){
    std::cout << "Hover the interactive button\n";
    is_hovered_ = true;
}

void ButtonRectInteractive::OnIdle(){
    std::cout << "Idle the interactive button\n";
    is_hovered_ = false;
}

void ButtonRectInteractive::Draw(sf::RenderWindow* window) {
    sf::Sprite& sprite = is_hovered_ ? sprite_hover_ : sprite_;
    window->draw(sprite);
}
