//
// Created by Admin on 16.06.2024.
//

#include "ReplaceSkillCommand.h"
#include "../../../GameController.h"
#include "../../Scenes/GameScene.h"

void ReplaceSkillCommand::fire() {
    auto& player = GameController::getInstance()->player;

    if(activeSkillToSet_){
        if (numberOfSkill_ == 1){
            player.setActiveSkill1(std::move(*activeSkillToSet_));
        } else if (numberOfSkill_ == 2){
            player.setActiveSkill2(std::move(*activeSkillToSet_));
        }
    } else if (passiveSkillToSet_){
        if (numberOfSkill_ == 1){
            player.setPassiveSkill1(std::move(*passiveSkillToSet_));
        } else if (numberOfSkill_ == 2){
            player.setPassiveSkill2(std::move(*passiveSkillToSet_));
        }
    }

    GameController::getInstance()->sceneManager.changeScene(std::make_unique<GameScene>());

}
