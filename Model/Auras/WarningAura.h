#pragma once

#include "Aura.h"
#include "../Spells/Spell.h"

class WarningAura : public Aura {
    std::unique_ptr<Aura> auraToPut;

public:
    WarningAura(sf::Vector2f position, float radius, float lifeTime, float cooldown, Character* creator, AllyOrEnemy allyOrEnemy, std::unique_ptr<Aura> aura)
    : Aura(position, radius, lifeTime, cooldown, creator, allyOrEnemy, sf::Color::White), auraToPut(std::move(aura)){}

    void applyEffect(Character&) override { };
    void applyProjectileEffect(Magicball&) override { };
    void actionOnEnd() override;

};

