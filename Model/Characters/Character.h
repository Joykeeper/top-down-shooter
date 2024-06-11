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

    AllyOrEnemy allyOrEnemy;

    std::vector<std::unique_ptr<Effect>> effects;

public:
    Character(sf::Vector2f pos, sf::Vector2f size, int health, float moveSpeed,AllyOrEnemy aRE):
    GameObject(pos, size), health_(health), moveSpeed_(moveSpeed),
                       allyOrEnemy(aRE){};

    virtual ~Character() = default;

    float getMoveSpeed() const;
    int getHealth() const;

    AllyOrEnemy getAllyOrEnemy() const;

    void setMoveSpeed(float);
    void setHealth(int);

    void addEffect(std::unique_ptr<Effect> effect);
    void removeEffect(const Effect& effect);
    std::vector<std::unique_ptr<Effect>>& getEffects();

    virtual void move(sf::Vector2f direction);
};

