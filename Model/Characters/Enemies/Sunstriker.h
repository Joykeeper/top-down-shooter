#pragma once


#include "Enemy.h"
#include "../../Spells/Sunstrike.h"
#include "../Behaviors/MovementBehaviors/RandomMovement.h"

class Sunstriker : public Enemy{
public:
    Sunstriker(sf::Vector2f pos, float sunstrikeArea = 150):
    Enemy(pos, 7, std::make_unique<Sunstrike>(this, sunstrikeArea), 100, sf::Color(232, 81, 82), 1.5,
          std::make_unique<RandomMovement>(pos)){};

    void attack() override;
    bool checkAttackConditions() override;
};

