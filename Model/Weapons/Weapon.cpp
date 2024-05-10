//
// Created by Admin on 05.05.2024.
//

#include "Weapon.h"

float Weapon::getShootingCooldown() const {
    return this->SHOOTING_COOLDOWN;
}

void Weapon::setShootingCooldown(float amount) {
    this->SHOOTING_COOLDOWN = amount;
}


Magicball* Weapon::shootProjectile(sf::Vector2f direction) {
    setTimeFromLastShot(0);
    return new Magicball(this->position_, direction, this->allyOrEnemy_);
}

float Weapon::getTimeFromLastShot() const {
    return this->timeFromLastShot_;
}

void Weapon::setTimeFromLastShot(float time) {
    this->timeFromLastShot_ = time;
}
