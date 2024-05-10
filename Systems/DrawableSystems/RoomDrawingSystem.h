#pragma once


#include "../DrawableSystem.h"

class RoomDrawingSystem : public DrawableSystem {
    void draw(sf::RenderWindow&) const override;
};

