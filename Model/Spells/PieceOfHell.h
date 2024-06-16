#pragma once

#include "Spell.h"

class PieceOfHell : public Spell{
    float auraTime;
    float radius;
public:
    PieceOfHell(Character* character, float radius=300, float time = 5) : Spell(character, 3, "Piece of hell"),
    auraTime(time), radius(radius){};
    void cast(sf::Vector2f={}) override;
};
