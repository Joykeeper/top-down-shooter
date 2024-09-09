//
// Created by Admin on 05.06.2024.
//

#include <iostream>
#include "Necromancer.h"
#include "../../Interactables/GateToNextLevel.h"
#include "../Behaviors/MovementBehaviors/MovementFromPlayer.h"

Necromancer::Necromancer(sf::Vector2f pos): Enemy(pos, 5, std::make_unique<AriseSpell>(this), 50, sf::Color(11, 146, 38),  2,
                                                  std::make_unique<MovementFromPlayer>()){
        chooseInteractableOnDeath();

    if (!this->getTexture().loadFromFile("assets/AdeptNecromancer.png"))
    {
        std::cout << "Couldn't load image";
    }

    this->getAnimationHandler().setSpriteSheet(this->getTexture());
    this->getAnimationHandler().setSpriteScale(sf::Vector2f (5,5));


//    this->getSprite().setTexture(this->getTexture());
//    this->getSprite().setTextureRect(sf::IntRect(0, 0, 16, 16));
//    this->getSprite().setScale(5, 5);
};

void Necromancer::attack() {
    timeTillEndOfCast = CASTING_TIME;

    spell->cast(sf::Vector2f(position_.x + 100, position_.y) );
}

bool Necromancer::checkAttackConditions() {
    if (spell->getTimeTillNext() > 0) return false;
    return true;
}
