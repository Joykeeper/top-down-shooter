//
// Created by Admin on 14.06.2024.
//

#include "ASPDBuff.h"
#include "../Effects/AttackSpeedEffect.h"

void ASPDBuff::cast(sf::Vector2f) {
    timeTillNext = COOL_DOWN;

    caster->addEffect(std::make_unique<AttackSpeedEffect>(attackSpeedBonus, effectTime));
}
