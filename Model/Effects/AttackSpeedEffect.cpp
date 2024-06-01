//
// Created by Admin on 20.05.2024.
//

#include "AttackSpeedEffect.h"
#include "../Characters/Character.h"

void AttackSpeedEffect::effect(Character &c) {
    Effect::effect(c);

    auto w = c.getWeapon();
    w.setShootingCooldown(w.getShootingCooldown() - attackSpeedBonus);
}

void AttackSpeedEffect::uneffect(Character &c) {
    if(!effecting) return;

    auto w = c.getWeapon();
    w.setShootingCooldown(w.getShootingCooldown() + attackSpeedBonus);

    Effect::uneffect(c);
}
