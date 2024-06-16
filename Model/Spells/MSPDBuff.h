#pragma once


#include "Spell.h"

class MSPDBuff : public Spell{
    float speedBonus;
    float effectTime;
public:
    MSPDBuff(Character* character, float speedBonus=50, float time = 3) : Spell(character, 3, "Speed Up"),
    speedBonus(speedBonus), effectTime(time){};
    void cast(sf::Vector2f={}) override;
};

