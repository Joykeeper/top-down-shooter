#pragma once


#include "Spell.h"

class Sunstrike : public Spell{
    float sunstrikeRadius;
public:
    Sunstrike(Character* character, float radius=200) : Spell(character, 4, "Sunstrike"), sunstrikeRadius(radius){};
    void cast(sf::Vector2f={}) override;
};

