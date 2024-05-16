#pragma once


#include "../DrawableSystem.h"

class InteractableDrawingSystem : public DrawableSystem{
    void draw(sf::RenderWindow&) const override;
};

