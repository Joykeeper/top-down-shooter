#pragma once


#include "../UpdatableSystem.h"

class EffectRemovingSystem : public UpdatableSystem{
public:
    void update(sf::Time) const override;
};