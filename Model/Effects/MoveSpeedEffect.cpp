//
// Created by Admin on 17.05.2024.
//

#include "MoveSpeedEffect.h"
#include "../Characters/Character.h"

void MoveSpeedEffect::effect(Character &c, float dt) {
    this->Effect::effect(c);
    c.setMoveSpeed(c.getMoveSpeed() + moveSpeedBonus);
}

void MoveSpeedEffect::uneffect(Character &c) {
    if (!effecting){
        return;
    }

    c.setMoveSpeed(c.getMoveSpeed() - moveSpeedBonus);

    this->Effect::uneffect(c);
}
