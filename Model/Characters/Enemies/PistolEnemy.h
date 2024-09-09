#pragma once

#include <iostream>
#include "../../Weapons/Pistol.h"

#include "Enemy.h"
#include "../../Spells/BallSpell.h"
#include "../Behaviors/MovementBehaviors/RangeHoldingMovement.h"
#include "../Behaviors/MovementBehaviors/MovementFromPlayer.h"


class PistolEnemy : public Enemy{
    float shootingRadius;
public:
    PistolEnemy(sf::Vector2f pos, float shootingRadius=250):
    Enemy(pos, 10, std::make_unique<BallSpell>(this), 50 , sf::Color(106, 67, 241), 0.01, std::make_unique<RangeHoldingMovement>(shootingRadius)),
    shootingRadius(shootingRadius){

        if (!this->getTexture().loadFromFile("assets/PistolEnemy.png"))
        {
            std::cout << "Couldn't load image";
        }

        this->getAnimationHandler().setSpriteSheet(this->getTexture());
        this->getAnimationHandler().setSpriteScale(sf::Vector2f (5,5));

//        this->getSprite().setTexture(this->getTexture());
//        this->getSprite().setTextureRect(sf::IntRect(0, 0, 16, 16));


    };

    void attack() override;
    bool checkAttackConditions() override;
    float getShootingRadius() const;
};

