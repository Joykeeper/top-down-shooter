//
// Created by Admin on 05.05.2024.
//

#include "Weapon.h"
#include "../Magicball.h"


float Weapon::getShootingCooldown() const {
    return this->shootingCooldown;
}

void Weapon::setShootingCooldown(float amount) {
    this->shootingCooldown = amount;
}


std::unique_ptr<Magicball> Weapon::shootProjectile(sf::Vector2f direction) {
    setTimeFromLastShot(0);
    return std::make_unique<Magicball>(this->position_, direction, this->allyOrEnemy_);
}

float Weapon::getTimeFromLastShot() const {
    return this->timeFromLastShot_;
}

void Weapon::setTimeFromLastShot(float time) {
    this->timeFromLastShot_ = time;
}
