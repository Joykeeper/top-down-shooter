#pragma once

#include "Effect.h"

class AttackSpeedEffect : public Effect{
    float attackSpeedBonus;
public:
    AttackSpeedEffect(float attackSpeedBonus, double effectTime):
            Effect(effectTime), attackSpeedBonus(attackSpeedBonus){};

    void effect(Character&) override;
    void uneffect(Character&) override;
};

