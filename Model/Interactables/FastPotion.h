#pragma once

#include <iostream>
#include "Interactable.h"

class FastPotion : public Interactable{
    float speedIncrease;
public:
    FastPotion(sf::Vector2f pos, float speedIncrease): Interactable(pos, {48, 48}, 20, sf::Color(213, 171, 8)),
                                                       speedIncrease(speedIncrease){
        if (!this->getTexture().loadFromFile("assets/potions.png"))
        {
            std::cout << "Couldn't load image";
        }

        this->getSprite().setTexture(this->getTexture());
        this->getSprite().setTextureRect(sf::IntRect(32, 32, 16, 16));
        this->getSprite().setScale(3, 3);
    };
    void interact(Player&) override;

};

