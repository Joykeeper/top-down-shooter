#pragma once

#include "Effect.h"

class BurningEffect : public Effect{
    float attackPerTime;
    float FREQUENCY;
    float timeTillBurn;
public:
    BurningEffect(float attackPerTime, float frequency, double effectTime, bool passive=false):
            Effect(effectTime, "Burning", passive), attackPerTime(attackPerTime), FREQUENCY(frequency),
            timeTillBurn(0){};

    void effect(Character&, float deltaTime) override;
    void uneffect(Character&) override {};
};


