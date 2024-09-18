#include "sphere_buttons.h"

float LinearTransition::operator()(float currentFactor, float speed) const {
    return currentFactor + speed;
}

float SinTransition::operator()(float currentFactor, float speed) const {
    return currentFactor + (1.f - currentFactor) * std::sin(speed * M_PIf / 2);
}

float EaseOutTransition::operator()(float currentFactor, float speed) const {
    return currentFactor + (speed * (1.f - (currentFactor * currentFactor)));
}

float EaseInOutTransition::operator()(float currentFactor, float speed) const {
    if (currentFactor < 0.5f) {
        return currentFactor + (speed * 2.f * (currentFactor + 0.5f) * (currentFactor + 0.5f));
    }
    else {
        return currentFactor + (speed * (-2.f * currentFactor * currentFactor + 4.f * currentFactor - 1.f));
    }
}

float DumpTransition::operator()(float current, float speed) const {
    return speed > 0.f ? 1.f : 0.f;
}

ButtonAddLightSource::ButtonAddLightSource(const sf::Sprite& sprite,
                                           const sf::Sprite& sprite_hover,
                                           Sphere::Renderer* renderer,
                                           const vec3<float> pos,
                                           const vec3<float> color,
                                           const TransitionFunctor& transitionFunc)
    : TGP::ButtonRectBase(sprite),
      sprite_hover_(sprite_hover),
      renderer_(renderer),
      pos_(pos),
      color_(color),
      is_on_(false),
      transitionFunc_(transitionFunc) {}

void ButtonAddLightSource::OnIdle() {
    if (is_on_) {
        ChangeTransitionFactor(+kTransitionSpeed);
    }
    else {
        ChangeTransitionFactor(-kTransitionSpeed);
    }

}

void ButtonAddLightSource::OnHover() {
    ChangeTransitionFactor(+kTransitionSpeed);
}

void ButtonAddLightSource::ChangeTransitionFactor(float value) {
    transitionFactor_ = transitionFunc_(transitionFactor_, value);
    if (transitionFactor_ < 0.0f) {
        transitionFactor_ = 0.f; 
    }

    if (transitionFactor_ > 1.0f) {
        transitionFactor_ = 1.0f;
    }
}

void ButtonAddLightSource::OnPress() {}

void ButtonAddLightSource::OnRelease() {
    if (!is_on_) {
        renderer_->AddLightSource(pos_, color_);
        renderer_->Render();
        is_on_ = true;
    }
}

void ButtonAddLightSource::Draw(sf::RenderWindow* window) {
    assert(0.f <= transitionFactor_ && transitionFactor_ <= 1.f);

    sf::Uint8  idleAlpha = static_cast<sf::Uint8>(255 * (1.0f - transitionFactor_));
    sf::Uint8 hoverAlpha = static_cast<sf::Uint8>(255 * transitionFactor_);

    sprite_      .setColor(sf::Color(255u, 255u, 255u,  idleAlpha));
    sprite_hover_.setColor(sf::Color(255u, 255u, 255u, hoverAlpha));

    window->draw(sprite_hover_);
    window->draw(sprite_);
}
