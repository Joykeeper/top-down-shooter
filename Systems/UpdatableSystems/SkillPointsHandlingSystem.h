#pragma once

#include "../UpdatableSystem.h"

class SkillPointsHandlingSystem : public UpdatableSystem{
    void update(sf::Time) const override;
};

