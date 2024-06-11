#pragma once


#include "MovementBehavior.h"

class MovementTowardsPlayer : public MovementBehavior{
public:
    sf::Vector2f nextMove(sf::Vector2f curPos) override;
};

