#pragma once
#include "SFML/Graphics.hpp"
#include "../DrawableSystem.h"


struct PlayerDrawingSystem : public DrawableSystem{
    void draw(sf::RenderWindow &window) const override;
};



