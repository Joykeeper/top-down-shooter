#pragma once


#include <iostream>
#include "Enemy.h"
#include "../../Spells/Sunstrike.h"
#include "../Behaviors/MovementBehaviors/RandomMovement.h"

class Sunstriker : public Enemy{
public:
    Sunstriker(sf::Vector2f pos, float sunstrikeArea = 150):
    Enemy(pos, 7, std::make_unique<Sunstrike>(this, sunstrikeArea), 100, sf::Color(232, 81, 82), 1.5,
          std::make_unique<RandomMovement>(pos)){
        if (!this->getTexture().loadFromFile("assets/Sunstriker.png"))
        {
            std::cout << "Couldn't load image";
        }

        this->getAnimationHandler().setSpriteSheet(this->getTexture());
        this->getAnimationHandler().setSpriteScale(sf::Vector2f (5,5));


//        this->getSprite().setTexture(this->getTexture());
//        this->getSprite().setTextureRect(sf::IntRect(0, 0, 16, 16));
//        this->getSprite().setScale(5, 5);
    };

    void attack() override;
    bool checkAttackConditions() override;
};

