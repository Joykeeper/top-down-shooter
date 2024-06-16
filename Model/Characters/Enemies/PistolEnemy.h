#pragma once

#include "../../Weapons/Pistol.h"

#include "Enemy.h"
#include "../../Spells/BallSpell.h"
#include "../Behaviors/MovementBehaviors/RangeHoldingMovement.h"
#include "../Behaviors/MovementBehaviors/MovementFromPlayer.h"


class PistolEnemy : public Enemy{
    float shootingRadius;
public:
    PistolEnemy(sf::Vector2f pos, float shootingRadius=250):
    Enemy(pos, 10, std::make_unique<BallSpell>(this), 50 , sf::Color(106, 67, 241), 0.01, std::make_unique<RangeHoldingMovement>(shootingRadius)),
    shootingRadius(shootingRadius){};

    void attack() override;
    bool checkAttackConditions() override;
    float getShootingRadius() const;
};

