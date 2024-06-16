//
// Created by Admin on 16.06.2024.
//

#include "BurningMagicBalls.h"
#include "../Characters/Player.h"
#include "../Spells/BurningBallSpell.h"

void BurningMagicBalls::effect(Character &c, float dt) {
    Effect::effect(c);

    if (typeid(c) == typeid(Player)){
        auto& k = (Player&) c;

        if (!givingSpell) givingSpell = std::make_unique<BurningBallSpell>(&c);

        if (!spellTakenAway){
            spellTakenAway = std::move(k.provideDefaultAttack());
            k.setDefaultAttack(std::move(givingSpell));
            givingSpell = nullptr;
        }

    };
}

void BurningMagicBalls::uneffect(Character &c) {
    if(!effecting) return;

    if (typeid(c) == typeid(Player)){
        auto& k = (Player&) c;
        givingSpell = k.provideDefaultAttack();
        k.setDefaultAttack(std::move(spellTakenAway));
        spellTakenAway = nullptr;
    };

    Effect::uneffect(c);
}