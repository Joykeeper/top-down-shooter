#pragma once
#include "SFML/Graphics.hpp"

class UpdatableSystem {
public:
    virtual void update(sf::Time) const = 0;
};
