#pragma once

#include "Interactable.h"

class FastPotion : public Interactable{
    float speedIncrease;
public:
    FastPotion(sf::Vector2f pos, float speedIncrease): Interactable(pos, {30, 30}, 20, sf::Color(213, 171, 8)),
                                                       speedIncrease(speedIncrease){};
    void interact(Player&) override;

};

