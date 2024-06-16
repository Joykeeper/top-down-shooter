#pragma once


#include "MovementBehavior.h"

class RangeHoldingMovement : public MovementBehavior{
    float rangeSize_;
public:
    RangeHoldingMovement(float rangeSize): MovementBehavior(), rangeSize_(rangeSize){}
    sf::Vector2f nextMove(sf::Vector2f curPos) override;
};


