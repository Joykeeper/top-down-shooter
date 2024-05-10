#pragma once

#include "../DrawableSystem.h"

class EnemyDrawingSystem : public DrawableSystem{
    void draw(sf::RenderWindow&) const override;
};

