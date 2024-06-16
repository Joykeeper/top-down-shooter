#pragma once

#include "../GameObject.h"
#include "../AllyOrEnemy.h"
#include "memory"
#include "WeaponType.h"

class Magicball;
class Effect;
class Spell;

class Weapon : public GameObject{
protected:
    float shootingCooldown;

    float timeFromLastShot_;

    AllyOrEnemy allyOrEnemy_;

public:
    Weapon(sf::Vector2f pos, sf::Vector2f size, float shootCD, AllyOrEnemy allyOrEnemy):
            GameObject(pos, size), shootingCooldown(shootCD),
            timeFromLastShot_(shootCD), allyOrEnemy_(allyOrEnemy) {};

    float getShootingCooldown() const;
    void setShootingCooldown(float);

    float getTimeFromLastShot() const;
    void setTimeFromLastShot(float);
    std::unique_ptr<Magicball> shootProjectile(sf::Vector2f direction);

    static std::vector<std::unique_ptr<Spell>> generateActiveSkills(int, WeaponType);
    static std::vector<std::unique_ptr<Effect>> generatePassiveSkills(int, WeaponType);
};


