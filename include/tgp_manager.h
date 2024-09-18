#ifndef TGP_MANAGER_H_
#define TGP_MANAGER_H_

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>
#include <vector>

namespace TGP {

template <typename T>
class ManagerBase {
public:

    void AddObject(std::unique_ptr<T> object) {
        objects_.push_back(std::move(object));
    }

    size_t Size() const {
        return objects_.size();
    }

    T* Get(size_t index) {
        if (index < objects_.size()) {
            return objects_[index].get();
        }
        return nullptr;
    }

    const T* Get(size_t index) const {
        if (index < Size()) {
            return objects_[index].get();
        }
        return nullptr;
    }

protected:
    std::vector<std::unique_ptr<T>> objects_;
};

class Drawable {
public:
    virtual void Draw(sf::RenderWindow* window) = 0;
};

class Updatable {
public:
    virtual void Update(const sf::Event& event, const sf::RenderWindow& window) = 0;
};

}

#endif // TGP_MANAGER_H_
