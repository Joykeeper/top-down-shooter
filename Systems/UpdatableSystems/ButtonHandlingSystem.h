#pragma once


#include "../UpdatableSystem.h"

class ButtonHandlingSystem : public UpdatableSystem{
public:
    void update(sf::Time) const override;
};

