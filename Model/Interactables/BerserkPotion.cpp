//
// Created by Admin on 16.06.2024.
//

#include "BerserkPotion.h"
#include "../Effects/AttackSpeedEffect.h"

void BerserkPotion::interact(Player &p) {
    p.addEffect(std::make_unique<AttackSpeedEffect>(aspdIncrease, 5));

    this->toDelete_ = true;
}
