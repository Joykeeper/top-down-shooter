#pragma once

#include <iostream>
#include "../Characters/Character.h"
#include "Interactable.h"

class HealingSalve : public Interactable{
    int healAmount;
public:
    HealingSalve(sf::Vector2f pos, int hP): Interactable(pos, {48, 48}, 20, sf::Color(26, 207, 143)), healAmount(hP){
        if (!this->getTexture().loadFromFile("assets/potions.png"))
        {
            std::cout << "Couldn't load image";
        }

        this->getSprite().setTexture(this->getTexture());
        this->getSprite().setTextureRect(sf::IntRect(0, 0, 16, 16));
        this->getSprite().setScale(3, 3);
    };
    void interact(Player&) override;

};
