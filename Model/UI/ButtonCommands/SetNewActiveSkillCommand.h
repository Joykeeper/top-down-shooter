#pragma once

#include "ButtonCommand.h"
#include "../../Spells/Spell.h"
#include <memory>




class SetNewActiveSkillCommand : public ButtonCommand {
    std::unique_ptr<Spell>* skillToSet_;

public:
    SetNewActiveSkillCommand(std::unique_ptr<Spell>* skillToSet): skillToSet_(skillToSet){};
    void fire() override;
};


