//
// Created by Admin on 07.06.2024.
//

#include "Spell.h"

void Spell::updateTimeTillNext(float time) {
    timeTillNext -= time;
    if(timeTillNext < 0) timeTillNext = 0;
}

float Spell::getTimeTillNext() {
    return timeTillNext;
}

float Spell::getCoolDown() {
    return COOL_DOWN;
}

std::string Spell::getName() {
    return name;
}

void Spell::setCoolDown(float t) {
    COOL_DOWN = t;
}
