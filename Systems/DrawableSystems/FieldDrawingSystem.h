#pragma once

#include "../DrawableSystem.h"
#include "SFML/Graphics.hpp"

class FieldDrawingSystem : public DrawableSystem{
    void draw(sf::RenderWindow&) const override;
};

