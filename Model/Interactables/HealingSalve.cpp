//
// Created by Admin on 10.05.2024.
//

#include "HealingSalve.h"
#include <iostream>

void HealingSalve::interact(Character &character) {
    if (!false){ //check if the healed amount isn't bigger than max health
        character.setHealth(character.getHealth() + this->healAmount);
        this->toDelete_ = true;
    }
}
