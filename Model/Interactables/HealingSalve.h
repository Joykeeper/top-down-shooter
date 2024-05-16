#pragma once


#include "../Characters/Character.h"
#include "Interactable.h"

class HealingSalve : public Interactable{
    int healAmount;
public:
    HealingSalve(sf::Vector2f pos, int hP): Interactable(pos, {30, 30}, 20), healAmount(hP){};
    void interact(Character&) override;

};
