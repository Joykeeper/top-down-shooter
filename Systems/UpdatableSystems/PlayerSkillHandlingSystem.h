#pragma once

#include "../UpdatableSystem.h"

class PlayerSkillHandlingSystem : public UpdatableSystem {
    void update(sf::Time) const override;
};

