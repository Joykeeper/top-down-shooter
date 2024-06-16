//
// Created by Admin on 16.06.2024.
//

#include "BurningEffect.h"
#include "../Characters/Character.h"

void BurningEffect::effect(Character &c, float deltaTime) {
    this->Effect::effect(c);

    if (timeTillBurn <= 0){
        c.setHealth(c.getHealth()-attackPerTime);
        timeTillBurn = FREQUENCY;
    } else{
        timeTillBurn -= deltaTime;
    }
}
