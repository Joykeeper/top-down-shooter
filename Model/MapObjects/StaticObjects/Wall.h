#pragma once

#include <iostream>
#include "../../GameObject.h"

class Wall : public GameObject{
public:
    static sf::Vector2f WALL_SIZE;
    Wall(sf::Vector2f position, sf::Vector2f size = WALL_SIZE): GameObject(position, size){
        if (!this->getTexture().loadFromFile("assets/stone_up_wall_40.png"))
        {
            std::cout << "Couldn't load image";
        }
        this->getSprite().setTexture(this->getTexture());
        this->getSprite().setTextureRect(sf::IntRect(0, 0, this->getSize().x, this->getSize().y));
    };
};

