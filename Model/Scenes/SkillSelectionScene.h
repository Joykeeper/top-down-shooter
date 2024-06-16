#pragma once

#include "Scene.h"
#include "../Spells/AriseSpell.h"
#include <memory>

class Spell;
class Effect;

class SkillSelectionScene : public Scene{
    std::vector<std::unique_ptr<Spell>> activeSkills;
    std::vector<std::unique_ptr<Effect>> passiveSkills;
public:
    SkillSelectionScene(std::vector<std::unique_ptr<Spell>> activeSkills, std::vector<std::unique_ptr<Effect>> passiveSkills):
    activeSkills(std::move(activeSkills)), passiveSkills(std::move(passiveSkills)){};
    void start() override;


};
