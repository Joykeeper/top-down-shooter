#pragma once


#include "../UpdatableSystem.h"

class EffectPuttingSystem : public UpdatableSystem{
public:
    void update(sf::Time) const override;
};
