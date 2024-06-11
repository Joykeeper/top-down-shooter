#pragma once

#include "../Character.h"
#include "../Behaviors/MovementBehaviors/MovementBehavior.h"
#include "../Behaviors/MovementBehaviors/MovementTowardsPlayer.h"
#include "../../Spells/Spell.h"

class Enemy : public Character{
protected:
    std::unique_ptr<MovementBehavior> movementBehavior;
    float castingTime;
    std::unique_ptr<Spell> spell;
public:
    Enemy(sf::Vector2f pos, std::unique_ptr<Spell> spell, float moveSpeed = 50) :
            Character(pos, sf::Vector2f(80, 80), 5, moveSpeed, AllyOrEnemy::ENEMY),
            movementBehavior(std::make_unique<MovementTowardsPlayer>()),
            spell(std::move(spell)){};

    sf::Vector2f getNextMove();
    virtual bool checkAttackConditions() = 0;

    virtual void attack() = 0;

    Spell& getSpell();

};

