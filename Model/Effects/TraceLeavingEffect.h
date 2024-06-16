#pragma once

#include "Effect.h"


class TraceLeavingEffect : public Effect{
    float radius;
    float damage;
    float FREQUENCY;
    float timeTillTrace;
public:
    TraceLeavingEffect(float radius, float damage, float frequency, double effectTime, bool passive=false):
            Effect(effectTime, "Fire steps", passive), radius(radius), damage(damage), FREQUENCY(frequency),
            timeTillTrace(0){};

    void effect(Character&, float deltaTime) override;
    void uneffect(Character&) override {};
};
