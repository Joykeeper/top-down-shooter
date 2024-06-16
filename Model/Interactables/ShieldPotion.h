#pragma once


#include "Interactable.h"

class ShieldPotion : public Interactable{
    int shieldBonus;
public:
    ShieldPotion(sf::Vector2f pos, int shP): Interactable(pos, {30, 30}, 20, sf::Color::Cyan), shieldBonus(shP){};
    void interact(Player&) override;

};

