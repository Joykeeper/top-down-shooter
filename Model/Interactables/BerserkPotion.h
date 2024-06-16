#pragma once

#include "Interactable.h"

class BerserkPotion : public Interactable{
    float aspdIncrease;
public:
    BerserkPotion(sf::Vector2f pos, float aspdIncrease): Interactable(pos, {30, 30}, 20, sf::Color(221, 1, 8)),
                                                         aspdIncrease(aspdIncrease){};
    void interact(Player&) override;

};

