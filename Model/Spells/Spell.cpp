//
// Created by Admin on 07.06.2024.
//

#include "Spell.h"

void Spell::updateTimeTillNext(float time) {
    timeTillNext -= time;
}

float Spell::getTimeTillNext() {
    return timeTillNext;
}
