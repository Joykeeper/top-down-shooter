#pragma once

#include "../Character.h"

class Enemy : public Character{

    float shootingRadius;
    bool playerInRadius;

public:
    Enemy(sf::Vector2f pos, float shootingRadius = 100, float moveSpeed = 10, std::unique_ptr<Weapon> weapon = nullptr) :
            Character(pos, sf::Vector2f(80, 80), 5, moveSpeed, AllyOrEnemy::ENEMY, std::move(weapon)), shootingRadius(shootingRadius), playerInRadius(false){};

    float getShootingRadius() const;
    void setPlayerInRadius(bool);
    bool isPlayerInRadius() const;
};

