#pragma once
#include "SFML/Graphics.hpp"

class GameObject {
protected:
    sf::Vector2f position_;
    sf::Vector2f size_;
public:
    explicit GameObject(sf::Vector2f pos, sf::Vector2f size={0, 0}):
    position_(pos), size_(size){};
    sf::Vector2f getPos() const;
    sf::Vector2f getSize() const;

    virtual void move(sf::Vector2f);
};

