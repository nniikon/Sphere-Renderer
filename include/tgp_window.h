#ifndef TGP_WINDOW_H_
#define TGP_WINDOW_H_

#include <SFML/Graphics.hpp>
#include "tgp_button_manager.h"
#include "tgp_pixel_area_manager.h"

namespace TGP {

class Window {
public:

    bool IsOpen();
    void Update();
    void Draw();
    void SetFramerate(unsigned int framerate);

    ManagerBase<ButtonBase>* GetButtonManager();
    ManagerBase<PixelArea>* GetPixelAreaManager();

    Window(unsigned int width, unsigned height, const char* window_name);
    ~Window();
    Window           (const Window&) = delete;
    Window& operator=(const Window&) = delete;

private:
    const unsigned int kChannelsPerPixel = 4u;

    sf::RenderWindow window_;
    ButtonManager    button_manager_;
    PixelAreaManager pixel_area_manager_;

};

}; // namespace

#endif // TGP_WINDOW_H_
