#pragma once


#include "Spell.h"

class ASPDBuff : public Spell{
    float attackSpeedBonus;
    float effectTime;
public:
    ASPDBuff(Character* character, float attackSpeedBonus=0.1, float time = 3) : Spell(character, 3, "Attack Up"),
                                                                           attackSpeedBonus(attackSpeedBonus), effectTime(time){};
    void cast(sf::Vector2f={}) override;
};

