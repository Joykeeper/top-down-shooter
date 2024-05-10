//
// Created by Admin on 05.05.2024.
//

#include <iostream>
#include "Character.h"

float Character::getMoveSpeed() const {
    return this->moveSpeed_;
}

int Character::getHealth() const{
    return this->health_;
}

void Character::setMoveSpeed(float mS) {
    this->moveSpeed_ = mS;
}

void Character::setHealth(int hP) {
    this->health_ = hP;
}

Weapon* Character::getWeapon() {
    if (this->weapon){
        return weapon;
    } else{
        return nullptr;
    }
}

void Character::move(sf::Vector2f vec) {
    this->position_ += vec;
    if (this->hasWeapon()){
        this->weapon->move(vec);
    }
}

bool Character::hasWeapon() {
    return weapon != nullptr;
}

Magicball* Character::shoot(sf::Vector2f dir) {
    if(hasWeapon()){
        return this->weapon->shootProjectile(dir);
    }
    return nullptr;
}

void Character::setWeapon(Weapon &weapon1) {
    this->weapon = &weapon1;
}
