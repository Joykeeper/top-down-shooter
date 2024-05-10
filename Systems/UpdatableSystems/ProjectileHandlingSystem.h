#pragma once
#include "../UpdatableSystem.h"

class ProjectileHandlingSystem : public UpdatableSystem{
public:
        void update(sf::Time) const override;
};
