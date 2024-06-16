#pragma once

#include "BallSpell.h"

class BurningBallSpell : public BallSpell{
public:
    BurningBallSpell(Character* character) : BallSpell(character){};
    void cast(sf::Vector2f dir);
};
