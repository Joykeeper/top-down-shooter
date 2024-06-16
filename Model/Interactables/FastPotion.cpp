//
// Created by Admin on 16.06.2024.
//

#include "FastPotion.h"
#include "../Effects/MoveSpeedEffect.h"

void FastPotion::interact(Player &p) {
    p.addEffect(std::make_unique<MoveSpeedEffect>(speedIncrease, 5));
    this->toDelete_ = true;
}
