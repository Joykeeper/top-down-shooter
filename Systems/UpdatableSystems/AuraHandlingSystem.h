#pragma once

#include "../UpdatableSystem.h"

class AuraHandlingSystem : public UpdatableSystem{
public:
    void update(sf::Time) const override;
};
