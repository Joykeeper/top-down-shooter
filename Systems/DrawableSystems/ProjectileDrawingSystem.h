#pragma once
#include "../DrawableSystem.h"

class ProjectileDrawingSystem : public DrawableSystem{
    void draw(sf::RenderWindow&) const override;
};

