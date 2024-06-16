#pragma once

#include "MovementBehavior.h"

class MovementFromPlayer : public MovementBehavior{
public:
    sf::Vector2f nextMove(sf::Vector2f curPos) override;
};


