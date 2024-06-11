//
// Created by Admin on 03.05.2024.
//

#include "Enemy.h"

sf::Vector2f Enemy::getNextMove() {
    return movementBehavior->nextMove(position_);
}

Spell &Enemy::getSpell() {
    return *spell;
}

