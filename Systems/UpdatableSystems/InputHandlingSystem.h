#pragma once

#include "../../Model/Characters/Player.h"
#include "../UpdatableSystem.h"

class InputHandlingSystem : public UpdatableSystem{
public:
    void update(sf::Time) const override;
};
