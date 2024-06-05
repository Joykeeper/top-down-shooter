#pragma once

#include "../GameObject.h"
#include <memory>
#include <map>
#include "../Weapons/Weapon.h"
#include "CharacterState.h"

#include "../Effects/Effect.h"

class Character : public GameObject{
protected:
    float moveSpeed_;
    int health_;
    std::unique_ptr<Weapon> weapon;
    AllyOrEnemy allyOrEnemy;
    //CharacterState state;

    //std::map<CharacterState, std::vector<sf::Sprite>>

    std::vector<std::unique_ptr<Effect>> effects;

public:
    Character(sf::Vector2f pos, sf::Vector2f size, int health, float moveSpeed,AllyOrEnemy aRE, std::unique_ptr<Weapon> weapon = nullptr):
    GameObject(pos, size), health_(health), moveSpeed_(moveSpeed),
                       allyOrEnemy(aRE), weapon(std::move(weapon)){};

    virtual ~Character() = default;

    float getMoveSpeed() const;
    int getHealth() const;
    Weapon& getWeapon();

    AllyOrEnemy getAllyOrEnemy() const;

    bool hasWeapon();
    void setWeapon(std::unique_ptr<Weapon>);
    std::unique_ptr<Magicball> shoot(sf::Vector2f);

    void setMoveSpeed(float);
    void setHealth(int);

    void addEffect(std::unique_ptr<Effect> effect);
    void removeEffect(const Effect& effect);
    std::vector<std::unique_ptr<Effect>>& getEffects();

    void move(sf::Vector2f direction);
};

