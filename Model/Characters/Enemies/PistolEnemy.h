#pragma once

#include "../../Weapons/Pistol.h"

#include "Enemy.h"

class PistolEnemy : public Enemy{
public:
    PistolEnemy(sf::Vector2f pos={}): Enemy(pos, 300, 100, new Pistol(pos, AllyOrEnemy::ENEMY)){};
};

