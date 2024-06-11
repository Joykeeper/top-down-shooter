#pragma once


#include "Aura.h"

class BurningAura : public Aura {
    int damagePerTime;

public:
    BurningAura(sf::Vector2f position, float radius, float lifeTime, float cooldown, Character* creator, AllyOrEnemy allyOrEnemy, int damagePerTime)
            : Aura(position, radius, lifeTime, cooldown, creator, allyOrEnemy, sf::Color::Red), damagePerTime(damagePerTime) {}

    void applyEffect(Character&) override;
    void applyProjectileEffect(Magicball&) override { };
    void actionOnEnd() override { };

};
