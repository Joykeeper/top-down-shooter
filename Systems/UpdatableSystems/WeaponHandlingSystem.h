#pragma once

#include "../UpdatableSystem.h"


class WeaponHandlingSystem : public UpdatableSystem{
    void update(sf::Time dt) const override;
};

