#pragma once

#include "../DrawableSystem.h"

class WeaponDrawingSystem : public DrawableSystem {
    void draw(sf::RenderWindow&) const override;
};

