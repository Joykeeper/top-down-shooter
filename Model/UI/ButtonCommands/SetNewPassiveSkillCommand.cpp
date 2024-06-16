//
// Created by Admin on 15.06.2024.
//

#include "SetNewPassiveSkillCommand.h"
#include "../../../GameController.h"
#include "../../Scenes/GameScene.h"
#include "../../Scenes/SkillReplacingScene.h"

void SetNewPassiveSkillCommand::fire() {
    auto& player = GameController::getInstance()->player;
    if (player.getPassiveSkill1() && player.getPassiveSkill2()){

        GameController::getInstance()->sceneManager.changeScene(std::make_unique<SkillReplacingScene>(nullptr, skillToSet_));

    }else if (player.getPassiveSkill1()){

        player.setPassiveSkill1(std::move(*skillToSet_));
        GameController::getInstance()->sceneManager.changeScene(std::make_unique<GameScene>());

    } else {

        player.setPassiveSkill2(std::move(*skillToSet_));
        GameController::getInstance()->sceneManager.changeScene(std::make_unique<GameScene>());

    }
}
