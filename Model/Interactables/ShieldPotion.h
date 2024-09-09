#pragma once


#include <iostream>
#include "Interactable.h"

class ShieldPotion : public Interactable{
    int shieldBonus;
public:
    ShieldPotion(sf::Vector2f pos, int shP): Interactable(pos, {48, 48}, 20, sf::Color::Cyan), shieldBonus(shP){
        if (!this->getTexture().loadFromFile("assets/potions.png"))
        {
            std::cout << "Couldn't load image";
        }

        this->getSprite().setTexture(this->getTexture());
        this->getSprite().setTextureRect(sf::IntRect(16, 16, 16, 16));
        this->getSprite().setScale(3, 3);
    };
    void interact(Player&) override;

};

