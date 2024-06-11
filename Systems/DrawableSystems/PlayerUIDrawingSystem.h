#pragma once

#include "../DrawableSystem.h"

class PlayerUIDrawingSystem : public DrawableSystem{
    void draw(sf::RenderWindow &window) const override;
};
