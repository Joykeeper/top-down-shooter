#pragma once

#include "../UpdatableSystem.h"

class SpellHandlingSystem : public UpdatableSystem{
    void update(sf::Time) const override;
};


