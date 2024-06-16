#pragma once

#include "../UpdatableSystem.h"

class LevelHandlingSystem : public UpdatableSystem {
    void update(sf::Time) const override;
};
