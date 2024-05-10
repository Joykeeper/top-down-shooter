#pragma once
#include "SFML/Graphics.hpp"

class DrawableSystem {
public:
    virtual void draw(sf::RenderWindow &window) const = 0;
};

