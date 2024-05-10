#pragma once
#include "SFML/Graphics.hpp"

class GameObject {
protected:
    sf::Vector2f position_;
public:
    explicit GameObject(sf::Vector2f pos): position_(pos){};
    sf::Vector2f getPos() const;

    virtual void move(sf::Vector2f);
};

