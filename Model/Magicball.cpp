//
// Created by Admin on 03.05.2024.
//

#include "Magicball.h"

sf::Vector2f Magicball::getDirection() {
    return this->direction;
}

float Magicball::getSpeed() {
    return this->speed;
}

int Magicball::getDamage() {
    return this->damage;
}

float Magicball::getLifeTime() {
    return this->lifeTime;
}

void Magicball::setLifeTime(float t) {
    this->lifeTime = t;
}

void Magicball::setDirection(sf::Vector2f dir) {
    this->direction = dir;
}

AllyOrEnemy Magicball::getAllyOrEnemy() const {
    return this->allyOrEnemy;
}

void Magicball::addEffect(std::unique_ptr<Effect> effect) {
    this->characterEffects.push_back(std::move(effect));
}

void Magicball::removeEffect(const Effect &effect) {
    auto it = std::find_if(characterEffects.begin(), characterEffects.end(),
                           [&effect](const std::unique_ptr<Effect>& ptr) {
                               return ptr.get() == &effect;
                           });
    if (it != characterEffects.end()) {
        characterEffects.erase(it);
    }
}

std::vector<std::unique_ptr<Effect>>& Magicball::getEffects() {
    return this->characterEffects;
}
