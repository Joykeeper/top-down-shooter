#pragma once


#include "../DrawableSystem.h"

class CameraMovingSystem : public DrawableSystem{
    void draw(sf::RenderWindow&) const override;
};

