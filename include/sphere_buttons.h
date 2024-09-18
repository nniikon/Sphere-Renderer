#ifndef SPHERE_BUTTONS_H_
#define SPHERE_BUTTONS_H_

#include "sphere_renderer.h"
#include "tgp_button.h"

#include <cassert>

using namespace TGP;

class TransitionFunctor {
public:
    virtual float operator()(float currentFactor, float speed) const = 0;
};

class LinearTransition : public TransitionFunctor {
public:
    virtual float operator()(float currentFactor, float speed) const override;
};

class SinTransition : public TransitionFunctor {
public:
    virtual float operator()(float currentFactor, float speed) const override;
};

class EaseOutTransition : public TransitionFunctor {
public:
    virtual float operator()(float currentFactor, float speed) const override;
};

class EaseInOutTransition : public TransitionFunctor {
public:
    virtual float operator()(float currentFactor, float speed) const override;
};

class DumpTransition : public TransitionFunctor {
public:
    virtual float operator()(float currentFactor, float speed) const override;
};

class ButtonAddLightSource : public TGP::ButtonRectBase {
public:
    ButtonAddLightSource(const sf::Sprite& sprite,
                         const sf::Sprite& sprite_hover,
                         Sphere::Renderer* renderer,
                         const vec3<float> pos,
                         const vec3<float> color,
                         const TransitionFunctor& transitionFunc);

    void OnIdle()    override;
    void OnHover()   override;
    void OnPress()   override;
    void OnRelease() override;

    void Draw(sf::RenderWindow* window) override;

private:
    constexpr static const float kTransitionSpeed = 0.01f;

    sf::Sprite sprite_hover_;
    Sphere::Renderer* renderer_;

    float transitionFactor_ = 0.f;

    const vec3<float> pos_;
    const vec3<float> color_;

    bool is_on_ = false;

    const TransitionFunctor& transitionFunc_;

    void ChangeTransitionFactor(float value);
};

#endif // SPHERE_BUTTONS_H_
