#pragma once


#include "Effect.h"

class MoveSpeedEffect : public Effect{
    float moveSpeedBonus;
public:
    MoveSpeedEffect(float percentage, double effectTime):
            Effect(effectTime), moveSpeedBonus(percentage){};

    void effect(Character&) override;
    void uneffect(Character&) override;
};

