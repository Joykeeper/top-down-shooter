//
// Created by Admin on 22.05.2024.
//

#include "ShieldPotion.h"
#include "../Characters/Player.h"

void ShieldPotion::interact(Character &c) {
    auto p = (Player*) &c;
    p->setShieldPoints(shieldBonus);

    this->toDelete_ = true;
}
