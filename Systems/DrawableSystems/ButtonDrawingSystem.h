#pragma once


#include "../DrawableSystem.h"

class ButtonDrawingSystem : public DrawableSystem{
    void draw(sf::RenderWindow&) const override;
};

