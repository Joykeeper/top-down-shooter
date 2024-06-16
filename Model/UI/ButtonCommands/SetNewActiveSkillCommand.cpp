//
// Created by Admin on 15.06.2024.
//

#include "SetNewActiveSkillCommand.h"
#include "../../../GameController.h"
#include "../../Scenes/SkillReplacingScene.h"
#include "../../Scenes/GameScene.h"

void SetNewActiveSkillCommand::fire() {
    auto& player = GameController::getInstance()->player;
    if (player.getActiveSkill1() && player.getActiveSkill2()){

        GameController::getInstance()->sceneManager.changeScene(std::make_unique<SkillReplacingScene>(skillToSet_));

    }else if (player.getActiveSkill1()){

        player.setActiveSkill2(std::move(*skillToSet_));
        GameController::getInstance()->sceneManager.changeScene(std::make_unique<GameScene>());

    } else {

        player.setActiveSkill1(std::move(*skillToSet_));
        GameController::getInstance()->sceneManager.changeScene(std::make_unique<GameScene>());

    }
}
