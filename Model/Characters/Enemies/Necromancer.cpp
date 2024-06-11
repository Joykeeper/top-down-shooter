//
// Created by Admin on 05.06.2024.
//

#include "Necromancer.h"

void Necromancer::attack() {
    spell->cast(sf::Vector2f(position_.x + 100, position_.y) );
}

bool Necromancer::checkAttackConditions() {
    if (spell->getTimeTillNext() > 0) return false;
    return true;
}
