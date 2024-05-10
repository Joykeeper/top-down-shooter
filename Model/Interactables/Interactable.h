#pragma once

#include "../Characters/Character.h"

class Interactable : public GameObject{
protected:
    float interactingRadius_;
    bool toDelete_;
public:
    Interactable(sf::Vector2f pos, sf::Vector2f size, float radius): GameObject(pos, size),
    interactingRadius_(radius), toDelete_(false){};
    virtual void interact(Character&) = 0;

    float getInteractingRadius() const;

    bool isToDelete();
};

