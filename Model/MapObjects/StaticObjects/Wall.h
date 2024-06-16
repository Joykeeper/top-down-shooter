#pragma once

#include "../../GameObject.h"

class Wall : public GameObject{
public:
    static sf::Vector2f WALL_SIZE;
    Wall(sf::Vector2f position, sf::Vector2f size = WALL_SIZE): GameObject(position, size){};
};

