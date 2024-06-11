#pragma once

#include <memory>
#include "../../Player.h"

class MovementBehavior {
public:
    MovementBehavior(){};

    virtual sf::Vector2f nextMove(sf::Vector2f curPos) = 0;
};

