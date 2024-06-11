#pragma once


#include "../UpdatableSystem.h"

class WallsCollisionSystem : public UpdatableSystem{
    void update(sf::Time) const override;
};

