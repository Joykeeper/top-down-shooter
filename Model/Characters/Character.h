#pragma once

#include "../GameObject.h"
#include "../Weapons/Weapon.h"

class Character : public GameObject{
    float moveSpeed_;
    int health_;
    Weapon* weapon;
    AllyOrEnemy allyOrEnemy;
public:
    Character(sf::Vector2f pos, sf::Vector2f size, int health, float moveSpeed,AllyOrEnemy aRE, Weapon* weapon = nullptr):
    GameObject(pos, size), health_(health), moveSpeed_(moveSpeed),
                       allyOrEnemy(aRE), weapon(weapon){};

    float getMoveSpeed() const;
    int getHealth() const;
    Weapon* getWeapon();

    bool hasWeapon();
    void setWeapon(Weapon&);
    Magicball* shoot(sf::Vector2f);

    void setMoveSpeed(float);
    void setHealth(int);

    void move(sf::Vector2f direction);
};

