//
// Created by Admin on 03.05.2024.
//

#include "Enemy.h"

float Enemy::getShootingRadius() const {
    return this->shootingRadius;
}

bool Enemy::isPlayerInRadius() const {
    return playerInRadius;
}

void Enemy::setPlayerInRadius(bool b) {
    this->playerInRadius = b;
}

