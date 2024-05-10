#pragma once

#include "Weapon.h"

class Pistol : public Weapon{
public:
    Pistol (sf::Vector2f pos, AllyOrEnemy allyOrEnemy) : Weapon(pos, 0.5 , allyOrEnemy){};
};

