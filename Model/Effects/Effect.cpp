//
// Created by Admin on 17.05.2024.
//

#include "Effect.h"

bool Effect::isFinished() const{
    return finished;
}

double Effect::getEffectTime() const{
    return effectTime;
}

double Effect::getTimeLeft() const {
    return timeLeft;
}

void Effect::setTimeLeft(double time) {
    this->timeLeft = time;
}

bool Effect::getEffecting() const {
    return effecting;
}

std::string Effect::getName() const {
    return name;
}

bool Effect::isPassive() {
    return passive_;
}

void Effect::setPassive(bool p) {
    passive_ = p;
}
