#pragma once

#include "../Magicball.h"

class Weapon : public GameObject{

    float SHOOTING_COOLDOWN;

    float timeFromLastShot_;

    AllyOrEnemy allyOrEnemy_;

public:
    Weapon(sf::Vector2f pos, float shootCD, AllyOrEnemy allyOrEnemy):
    GameObject(pos), SHOOTING_COOLDOWN(shootCD),
    timeFromLastShot_(shootCD), allyOrEnemy_(allyOrEnemy) {};

    float getShootingCooldown() const;
    void setShootingCooldown(float);

    float getTimeFromLastShot() const;
    void setTimeFromLastShot(float);
    Magicball* shootProjectile(sf::Vector2f direction);
};


