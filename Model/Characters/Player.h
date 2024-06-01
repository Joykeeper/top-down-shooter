#pragma once
#include "SFML/Graphics.hpp"
#include "Character.h"

class Player : public Character{
    int shieldPoints;

public:
    Player() : Character(sf::Vector2f(10, 10),
                         sf::Vector2f(60, 60), 10, 300, AllyOrEnemy::ALLY),
                         shieldPoints(0){};

    ~Player() override = default;

    int getShieldPoints() const;

    void setHealth(int);

    void setShieldPoints(int);
};

