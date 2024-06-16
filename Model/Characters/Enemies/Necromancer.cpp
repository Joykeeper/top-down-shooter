//
// Created by Admin on 05.06.2024.
//

#include "Necromancer.h"
#include "../../Interactables/GateToNextLevel.h"
#include "../Behaviors/MovementBehaviors/MovementFromPlayer.h"

Necromancer::Necromancer(sf::Vector2f pos): Enemy(pos, 5, std::make_unique<AriseSpell>(this), 50, sf::Color(11, 146, 38),  2,
                                                  std::make_unique<MovementFromPlayer>()){
        chooseInteractableOnDeath();
};

void Necromancer::attack() {
    timeTillEndOfCast = CASTING_TIME;

    spell->cast(sf::Vector2f(position_.x + 100, position_.y) );
}

bool Necromancer::checkAttackConditions() {
    if (spell->getTimeTillNext() > 0) return false;
    return true;
}
