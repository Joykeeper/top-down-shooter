#pragma once

#include "../../Weapons/Pistol.h"

#include "Enemy.h"
#include "../../Spells/BallSpell.h"
#include "../../Spells/AriseSpell.h"

class Necromancer : public Enemy{
public:
    Necromancer(sf::Vector2f pos={}): Enemy(pos, std::make_unique<AriseSpell>(this)){};

    void attack() override;
    bool checkAttackConditions() override;
};

