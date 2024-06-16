#pragma once

#include "../DrawableSystem.h"

class LabelDrawingSystem : public DrawableSystem{
    void draw(sf::RenderWindow&) const override;
};

