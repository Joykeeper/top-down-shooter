//
// Created by Admin on 16.06.2024.
//

#include <iostream>
#include "UpperNecromancer.h"
#include "../../Interactables/GateToNextLevel.h"
#include "../../Spells/AdvancedAriseSpell.h"
#include "../Behaviors/MovementBehaviors/RandomMovement.h"

void UpperNecromancer::attack() {
    timeTillEndOfCast = CASTING_TIME;

    spell->cast(sf::Vector2f(position_.x + 100, position_.y) );
}

bool UpperNecromancer::checkAttackConditions() {
    if (spell->getTimeTillNext() > 0) return false;
    return true;
}

UpperNecromancer::UpperNecromancer(sf::Vector2f pos): Enemy(pos, 100, std::make_unique<AdvancedAriseSpell>(this), 50, sf::Color(11, 146, 38),  2,
                                                            std::make_unique<RandomMovement>(pos)){
    interactableOnElimination = std::make_unique<GateToNextLevel>(pos);
    size_ = sf::Vector2f (150, 150);

    if (!this->getTexture().loadFromFile("assets/AdeptNecromancer.png"))
    {
        std::cout << "Couldn't load image";
    }

    this->getAnimationHandler().setSpriteSheet(this->getTexture());
    this->getAnimationHandler().setSpriteScale(sf::Vector2f (9.375f, 9.375f));

//    this->getSprite().setTexture(this->getTexture());
//    this->getSprite().setTextureRect(sf::IntRect(0, 0, 16, 16));
//    this->getSprite().setScale(9.375f, 9.375f);
};
