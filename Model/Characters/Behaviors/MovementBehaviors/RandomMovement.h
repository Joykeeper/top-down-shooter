#pragma once

#include "MovementBehavior.h"

class RandomMovement : public MovementBehavior{
    sf::Vector2f selectedDir_;
public:
    RandomMovement(sf::Vector2f curPos): selectedDir_(curPos){};
    sf::Vector2f nextMove(sf::Vector2f curPos) override;
};

