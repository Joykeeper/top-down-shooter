#pragma once


#include "../Characters/Character.h"
#include "Interactable.h"

class HealingSalve : public Interactable{
    int healAmount;
public:
    HealingSalve(sf::Vector2f pos, int hP): Interactable(pos, {30, 30}, 20, sf::Color(26, 207, 143)), healAmount(hP){};
    void interact(Player&) override;

};
