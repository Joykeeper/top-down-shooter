//
// Created by Admin on 05.06.2024.
//

#include "Aura.h"

sf::Vector2f Aura::getPosition() const {
    return position_;
}

float Aura::getRadius() const {
    return radius;
}

AllyOrEnemy Aura::getAllyOrEnemy() const {
    return allyOrEnemy;
}

Character& Aura::getCreator() {
    return *creator;
}

float Aura::getCoolDown() const {
    return EFFECT_COOL_DOWN;
}

float Aura::getTimeTillNextEffect() {
    return timeTillNextEffect;
}

void Aura::setTimeTillNextEffect(float t) {
    timeTillNextEffect = t;
}

void Aura::resetTimeTillNextEffect() {
    timeTillNextEffect = EFFECT_COOL_DOWN;
}

float Aura::getLifeTime() {
    return lifeTime;
}

void Aura::setLifeTime(float time) {
    lifeTime = time;
}

sf::Color Aura::getColor() const {
    return color_;
}

AnimationHandler &Aura::getAnimationHandler() {
    return animationHandler;
}
