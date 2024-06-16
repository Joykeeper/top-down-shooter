#pragma once

#include "Effect.h"
#include "AttackSpeedEffect.h"

class WaterConcentration : public AttackSpeedEffect{
public:
    WaterConcentration(double effectTime):
            AttackSpeedEffect(0.07, effectTime, "Water concentration", true){};
};

