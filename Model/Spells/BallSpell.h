#pragma once


#include "Spell.h"

class BallSpell : public Spell{
public:
    BallSpell(Character* character) : Spell(character, 0.3){};
    void cast(sf::Vector2f dir);
};

