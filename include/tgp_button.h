#ifndef TGP_BUTTON_H_
#define TGP_BUTTON_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "tgp_manager.h"
#include "tgp_vectors.h"

namespace TGP {

class ButtonBase : public Drawable {
public:
    virtual void OnHover  () = 0;
    virtual void OnIdle   () = 0;
    virtual void OnPress  () = 0;
    virtual void OnRelease() = 0;

    virtual bool DoesIntersect(vec2f pos) = 0;

    virtual ~ButtonBase() = default;
};

class ButtonRectBase : public ButtonBase {
public:
    bool DoesIntersect(vec2f pos)       override;
    void Draw(sf::RenderWindow* window) override;

    ButtonRectBase(const sf::Sprite& sprite);
    ~ButtonRectBase() override = default;

protected:
    sf::Sprite sprite_;
};

class ButtonRectTest : public ButtonRectBase {
public:
    void OnHover  () override;
    void OnIdle   () override;
    void OnPress  () override;
    void OnRelease() override;

    void some_function();
    ButtonRectTest(const sf::Sprite& sprite);
    ~ButtonRectTest() override = default;

private:
    const char* some_str = "Hello World!";
    int some_integer = 123;
};

class ButtonRectInteractive : public ButtonRectBase {
public:
    virtual void OnHover  () override;
    virtual void OnIdle   () override;

    void Draw(sf::RenderWindow* window) override;

    bool is_hovered_ = false;

    ButtonRectInteractive(const sf::Sprite& sprite, const sf::Sprite& sprite_hover);
    ~ButtonRectInteractive() override = default;

protected:
    sf::Sprite sprite_hover_;
};

} // namespace

#endif // TGP_BUTTON_H_
