#pragma once

#include "../../GameObject.h"

class Wall : public GameObject{
public:
    Wall(sf::Vector2f position, sf::Vector2f size = {40, 40}): GameObject(position, size){};
};

