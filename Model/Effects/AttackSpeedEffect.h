#pragma once

#include "Effect.h"

class AttackSpeedEffect : public Effect{
    float attackSpeedBonus;
public:
    AttackSpeedEffect(float attackSpeedBonus, double effectTime, std::string name = "Attack up", bool passive = false):
            Effect(effectTime, name, passive), attackSpeedBonus(attackSpeedBonus){};

    void effect(Character&, float dt = 0) override;
    void uneffect(Character&) override;
};

