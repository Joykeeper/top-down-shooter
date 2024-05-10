#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "AllyOrEnemy.h"

class Magicball : public GameObject{
    float speed;
    float lifeTime;
    int damage;
    AllyOrEnemy allyOrEnemy;

    sf::Vector2f direction;

public:
    Magicball(sf::Vector2f startPos, sf::Vector2f dir, AllyOrEnemy type) :
            GameObject(startPos, {40, 40}),  speed(1000), lifeTime(3), direction(dir), damage(1),
            allyOrEnemy(type){};

    sf::Vector2f getDirection();
    float getSpeed();
    float getLifeTime();
    void setLifeTime(float);
    void setDirection(sf::Vector2f);

    int getDamage();
    AllyOrEnemy getAllyOrEnemy() const;
};



