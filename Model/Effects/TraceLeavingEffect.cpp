//
// Created by Admin on 16.06.2024.
//

#include "TraceLeavingEffect.h"
#include "../Characters/Character.h"
#include "../Auras/BurningAura.h"
#include "../../GameController.h"

void TraceLeavingEffect::effect(Character &c, float deltaTime) {
    this->Effect::effect(c);

    if (timeTillTrace <= 0){

        auto trace = std::make_unique<BurningAura>(c.getPos(), radius, 2, 0.3,
                                                  &c, c.getAllyOrEnemy(), 1);
        GameController::getInstance()->auraHandler.add(std::move(trace));

        timeTillTrace = FREQUENCY;

    } else{
        timeTillTrace -= deltaTime;
    }
}
