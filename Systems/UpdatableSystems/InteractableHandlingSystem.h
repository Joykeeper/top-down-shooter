#pragma once


#include "../UpdatableSystem.h"

class InteractableHandlingSystem : public UpdatableSystem {
    void update(sf::Time) const override;
};
