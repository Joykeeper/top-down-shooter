#pragma once

#include "ButtonCommand.h"
#include "../../Spells/Spell.h"
#include "../../Effects/Effect.h"
#include <memory>


class ReplaceSkillCommand : public ButtonCommand {
    int numberOfSkill_;

    std::unique_ptr<Spell>* activeSkillToSet_;
    std::unique_ptr<Effect>* passiveSkillToSet_;
public:
    ReplaceSkillCommand(int numberOfSkill, std::unique_ptr<Spell>* activeSkillToSet_= nullptr, std::unique_ptr<Effect>* passiveSkillToSet_= nullptr):
    numberOfSkill_(numberOfSkill),activeSkillToSet_(activeSkillToSet_), passiveSkillToSet_(passiveSkillToSet_){};
    void fire() override;
};


