//
// Created by Admin on 12.06.2024.
//

#include "MSPDBuff.h"
#include "../Effects/MoveSpeedEffect.h"

void MSPDBuff::cast(sf::Vector2f) {
    timeTillNext = COOL_DOWN;

    caster->addEffect(std::make_unique<MoveSpeedEffect>(speedBonus, effectTime));
}
