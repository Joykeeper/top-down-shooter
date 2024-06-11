#pragma once


#include "Aura.h"

class ArisingAura : public Aura {
public:
    ArisingAura(sf::Vector2f position, int radius, Character* creator)
    : Aura(position, radius, 0.1, 0.1, creator, AllyOrEnemy::ENEMY, sf::Color::White) {}

    void applyEffect(Character&) override { };
    void applyProjectileEffect(Magicball&) override { };
    void actionOnEnd() override;

};

