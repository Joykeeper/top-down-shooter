#pragma once

#include "../../Weapons/Pistol.h"

#include "Enemy.h"
#include "../../Spells/BallSpell.h"

class PistolEnemy : public Enemy{
    float shootingRadius;
public:
    PistolEnemy(sf::Vector2f pos={}, float shootingRadius=250): Enemy(pos, std::make_unique<BallSpell>(this)),
    shootingRadius(shootingRadius){};

    void attack() override;
    bool checkAttackConditions() override;
    float getShootingRadius() const;
};

