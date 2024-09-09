#pragma once

#include <iostream>
#include "Interactable.h"

class BerserkPotion : public Interactable{
    float aspdIncrease;
public:
    BerserkPotion(sf::Vector2f pos, float aspdIncrease): Interactable(pos, {48, 48}, 20, sf::Color(221, 1, 8)),
                                                         aspdIncrease(aspdIncrease){
        if (!this->getTexture().loadFromFile("assets/potions.png"))
        {
            std::cout << "Couldn't load image";
        }

        this->getSprite().setTexture(this->getTexture());
        this->getSprite().setTextureRect(sf::IntRect(0, 16, 16, 16));
        this->getSprite().setScale(3, 3);
    };
    void interact(Player&) override;

};

