#pragma once

#include "Effect.h"
#include "../Spells/Spell.h"

class BurningMagicBalls : public Effect{
    std::unique_ptr<Spell> spellTakenAway;
    std::unique_ptr<Spell> givingSpell;
public:
    BurningMagicBalls(double effectTime, bool passive = false):
            Effect(effectTime, "Burning magic", passive){};

    void effect(Character&, float dt = 0) override;
    void uneffect(Character&) override;
};

