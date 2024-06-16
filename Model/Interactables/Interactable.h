#pragma once

#include "../Characters/Character.h"
#include "../Characters/Player.h"

class Interactable : public GameObject{
protected:
    float interactingRadius_;
    bool toDelete_;
    sf::Color color;
public:
    Interactable(sf::Vector2f pos, sf::Vector2f size, float radius, sf::Color color = sf::Color::Magenta): GameObject(pos, size),
    interactingRadius_(radius), toDelete_(false), color(color){};
    virtual void interact(Player&) = 0;

    float getInteractingRadius() const;

    bool isToDelete();
    sf::Color getColor();
};

