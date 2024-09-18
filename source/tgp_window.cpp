#include "tgp_window.h"

using namespace TGP;

Window::Window(unsigned int width, unsigned height, const char* window_name) 
    : window_(sf::VideoMode(width, height), window_name),
      button_manager_() {}

Window::~Window() {}

void Window::SetFramerate(unsigned int framerate) {
    window_.setFramerateLimit(framerate);
}

bool Window::IsOpen() {
    return window_.isOpen();
}

void Window::Update() {
    sf::Event event{};
    event.type = sf::Event::EventType::Count; // since EventType(0) is a close window event (wtf)
                                              // SFML, ever heard of NONE EVENT???
                                              // Using Count as EventType::None
    do {
        button_manager_.Update(event, window_);

        if (event.type == sf::Event::Closed) {
            window_.close();
        }

    } while(window_.pollEvent(event));
}

void Window::Draw() {
    window_.clear();

    button_manager_    .Draw(&window_);
    pixel_area_manager_.Draw(&window_);

    window_.display();
}

ManagerBase<ButtonBase>* Window::GetButtonManager() {
    return &button_manager_;
}

ManagerBase<PixelArea>* Window::GetPixelAreaManager() {
    return &pixel_area_manager_;
}
