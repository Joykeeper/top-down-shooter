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
    if (this->health_ < 0) this->health_ = 0;
    if (this->health_ > MAX_HEALTH) this->health_ = MAX_HEALTH;
}



void Character::move(sf::Vector2f vec) {
    this->position_ += vec;
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

AllyOrEnemy Character::getAllyOrEnemy() const {
    return allyOrEnemy;
}

int Character::getMaxHealth() const {
    return MAX_HEALTH;
}

void Character::setMaxHealth(int hp){
    this->MAX_HEALTH = hp;
}