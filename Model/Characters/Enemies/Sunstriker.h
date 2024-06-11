#pragma once


#include "Enemy.h"
#include "../../Spells/Sunstrike.h"

class Sunstriker : public Enemy{
public:
    Sunstriker(sf::Vector2f pos, float sunstrikeArea = 100):
    Enemy(pos, std::make_unique<Sunstrike>(this, sunstrikeArea)){};

    void attack() override;
    bool checkAttackConditions() override;
};

