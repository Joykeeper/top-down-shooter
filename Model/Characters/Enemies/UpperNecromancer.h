#pragma once

#include "Enemy.h"
#include "Necromancer.h"

class UpperNecromancer : public Enemy{
public:
    UpperNecromancer(sf::Vector2f pos={});

    void attack() override;
    bool checkAttackConditions() override;
};
