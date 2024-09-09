#pragma once

#include <memory>
#include "SFML/Graphics.hpp"
#include "UIComponent.h"

class PlayerUI {
public:
    std::unique_ptr<UIComponent> infoBlock;

    std::unique_ptr<UIComponent> activeSkillsBlock;

    std::unique_ptr<UIComponent> passiveSkillsBlock;

    PlayerUI();
};
