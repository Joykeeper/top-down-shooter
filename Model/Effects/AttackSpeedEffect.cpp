//
// Created by Admin on 20.05.2024.
//

#include <iostream>
#include "AttackSpeedEffect.h"
#include "../Characters/Character.h"
#include "../Characters/Player.h"
#include "../Spells/Spell.h"

void AttackSpeedEffect::effect(Character &c, float dt) {
    Effect::effect(c);

    if (typeid(c) == typeid(Player)){
        std::cout << "here lol \n";
        auto& k = (Player&) c;
        k.getDefaultAttack()->setCoolDown(k.getDefaultAttack()->getCoolDown() - attackSpeedBonus);
    };
}

void AttackSpeedEffect::uneffect(Character &c) {
    if(!effecting) return;

    if (typeid(c) == typeid(Player)){
        auto& k = (Player&) c;
        k.getDefaultAttack()->setCoolDown(k.getDefaultAttack()->getCoolDown() + attackSpeedBonus);
    };

    Effect::uneffect(c);
}
