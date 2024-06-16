#pragma once

#include <memory>
#include "Scene.h"
#include "../Spells/Spell.h"


class SkillReplacingScene : public Scene{
    std::unique_ptr<Spell>* activeSkillToSet;
    std::unique_ptr<Effect>* passiveSkillToSet;
public:
    SkillReplacingScene(std::unique_ptr<Spell>* activeSkillToSet = nullptr, std::unique_ptr<Effect>* passiveSkillToSet = nullptr):
    activeSkillToSet(activeSkillToSet), passiveSkillToSet(passiveSkillToSet){};
    void start() override;
};

