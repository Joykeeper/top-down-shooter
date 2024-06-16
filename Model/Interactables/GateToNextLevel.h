#pragma once

#include "Interactable.h"

class GateToNextLevel : public Interactable{
public:
    GateToNextLevel(sf::Vector2f pos): Interactable(pos, {300, 300}, 150){};
    void interact(Player&) override;

};

