//
// Created by Admin on 20.05.2024.
//

#include "AttackSpeedEffect.h"
#include "../Characters/Character.h"

void AttackSpeedEffect::effect(Character &c) {
    Effect::effect(c);

}

void AttackSpeedEffect::uneffect(Character &c) {
    if(!effecting) return;



    Effect::uneffect(c);
}
