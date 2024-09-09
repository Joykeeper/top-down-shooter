#pragma once

#include <iostream>
#include "Interactable.h"

class GateToNextLevel : public Interactable{
public:
    GateToNextLevel(sf::Vector2f pos): Interactable(pos, {320, 320}, 150){
        if (!this->getTexture().loadFromFile("assets/portals.png"))
        {
            std::cout << "Couldn't load image";
        }

        this->getSprite().setTexture(this->getTexture());
        this->getSprite().setTextureRect(sf::IntRect(192, 0, 32, 32));
        this->getSprite().setScale(10, 10);
    };
    void interact(Player&) override;

};

