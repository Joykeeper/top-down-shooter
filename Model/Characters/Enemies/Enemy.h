#pragma once

#include "../Character.h"
#include "../Behaviors/MovementBehaviors/MovementBehavior.h"
#include "../Behaviors/MovementBehaviors/MovementTowardsPlayer.h"
#include "../../Spells/Spell.h"
#include "../../Interactables/Interactable.h"
#include "../../Interactables/HealingSalve.h"


class Enemy : public Character{
protected:
    std::unique_ptr<MovementBehavior> movementBehavior;
    float CASTING_TIME;
    float timeTillEndOfCast;
    std::unique_ptr<Spell> spell;
    std::unique_ptr<Interactable> interactableOnElimination;

    sf::Color color;
public:
    Enemy(sf::Vector2f pos, int health, std::unique_ptr<Spell> spell, float moveSpeed, sf::Color color, float castingTime = 1,
          std::unique_ptr<MovementBehavior> movementBehavior = std::make_unique<MovementTowardsPlayer>());

    sf::Vector2f getNextMove();
    virtual bool checkAttackConditions() = 0;

    virtual void attack() = 0;

    float getTimeTillEndOfCast();
    float getCastingTime();

    std::unique_ptr<Interactable> provideInteractableOnDeath();
    void chooseInteractableOnDeath();

    void updateTimeTillEndOfCast(float dtime);

    Spell& getSpell();

    sf::Color getColor();
};

