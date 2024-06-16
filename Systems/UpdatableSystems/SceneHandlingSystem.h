#pragma once

#include "../UpdatableSystem.h"

class SceneHandlingSystem : public UpdatableSystem{
    void update(sf::Time) const override;
};
