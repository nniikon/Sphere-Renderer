#ifndef TGP_BUTTON_MANAGER_H_
#define TGP_BUTTON_MANAGER_H_

#include "tgp_button.h"
#include "tgp_manager.h"

#include <SFML/Window/Event.hpp>

namespace TGP {

class ButtonManager : public ManagerBase<ButtonBase>, Drawable, Updatable {
public:
    void Update(const sf::Event& event, const sf::RenderWindow& window) override;
    void Draw  (                              sf::RenderWindow* window) override;

    ButtonManager()  = default;
    ~ButtonManager();

private:
    void UpdateButton(ButtonBase* button, const sf::Event& event,
                                          const vec2f& mouse_pos_f);
};

}; // namespace

#endif // TGP_BUTTON_MANAGER_H_
