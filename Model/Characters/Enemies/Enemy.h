#pragma once

#include "../Character.h"

class Enemy : public Character{

    float shootingRadius;
    bool playerInRadius;

public:
    Enemy(sf::Vector2f pos={}, float shootingRadius = 100, float moveSpeed = 10, Weapon* weapon = nullptr) :
    Character(pos, 5, moveSpeed, AllyOrEnemy::ENEMY,weapon), shootingRadius(shootingRadius), playerInRadius(false){};

    float getShootingRadius() const;
    void setPlayerInRadius(bool);
    bool isPlayerInRadius() const;
};

