//
// Created by Admin on 05.05.2024.
//

#include <iostream>
#include "Character.h"
#include "../Magicball.h"


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

Weapon& Character::getWeapon() {
    if (this->weapon){
        return *weapon;
    } else{
        throw std::runtime_error("Character does not have a weapon");
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

std::unique_ptr<Magicball> Character::shoot(sf::Vector2f dir) {
    if(hasWeapon()){
        return std::move(this->weapon->shootProjectile(dir));
    }
    return nullptr;
}

void Character::setWeapon(std::unique_ptr<Weapon> weapon1) {
    this->weapon = std::move(weapon1);
}

void Character::addEffect(std::unique_ptr<Effect> effect) {
    this->effects.push_back(std::move(effect));
}

void Character::removeEffect(const Effect& effect) {
    auto it = std::find_if(effects.begin(), effects.end(),
                           [&effect](const std::unique_ptr<Effect>& ptr) {
                               return ptr.get() == &effect;
                           });
    if (it != effects.end()) {
        effects.erase(it);
    }
}

std::vector<std::unique_ptr<Effect>>& Character::getEffects() {
    return this->effects;
}
