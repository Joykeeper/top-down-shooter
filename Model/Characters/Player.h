#pragma once
#include "SFML/Graphics.hpp"
#include "Character.h"

class Player : public Character{

public:
    Player() : Character(sf::Vector2f(10, 10), 10, 300, AllyOrEnemy::ALLY){};
};

