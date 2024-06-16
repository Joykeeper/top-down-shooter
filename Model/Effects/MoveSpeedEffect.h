#pragma once


#include "Effect.h"

class MoveSpeedEffect : public Effect{
    float moveSpeedBonus;
public:
    MoveSpeedEffect(float moveSpeedBonus, double effectTime, bool passive=false):
            Effect(effectTime, "Speed up", passive), moveSpeedBonus(moveSpeedBonus){};

    void effect(Character&, float dt = 0) override;
    void uneffect(Character&) override;
};

