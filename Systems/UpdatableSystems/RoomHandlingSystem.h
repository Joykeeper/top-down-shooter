#pragma once

#include "../UpdatableSystem.h"

class RoomHandlingSystem : public UpdatableSystem{
    void update(sf::Time) const override;
};

