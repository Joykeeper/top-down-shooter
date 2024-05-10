#pragma once


#include "../UpdatableSystem.h"

class EnemyHandlingSystem : public UpdatableSystem{
    void update(sf::Time) const override;
};

