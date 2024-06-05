//
// Created by Admin on 05.06.2024.
//

#include "BurningAura.h"
#include "../Characters/Character.h"

void BurningAura::applyEffect(Character &character) {
    if (character.getAllyOrEnemy() != this->getAllyOrEnemy()){
        character.setHealth(character.getHealth() - damagePerTime);
    }
}
