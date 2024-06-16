#pragma once

#include "ButtonCommand.h"
#include <memory>
#include "../../Effects/Effect.h"

class SetNewPassiveSkillCommand : public ButtonCommand {
    std::unique_ptr<Effect>* skillToSet_;
public:
    SetNewPassiveSkillCommand(std::unique_ptr<Effect>* skillToSet): skillToSet_(skillToSet){};
    void fire() override;
};

