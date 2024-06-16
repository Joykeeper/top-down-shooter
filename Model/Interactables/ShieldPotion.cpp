//
// Created by Admin on 22.05.2024.
//

#include "ShieldPotion.h"
#include "../Characters/Player.h"

void ShieldPotion::interact(Player &c) {
    c.setShieldPoints(c.getShieldPoints() + shieldBonus);

    this->toDelete_ = true;
}
