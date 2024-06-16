//
// Created by Admin on 15.06.2024.
//

#include "SkillPointsHandlingSystem.h"
#include "../../GameController.h"

void SkillPointsHandlingSystem::update(sf::Time) const {
    auto& player = GameController::getInstance()->player;
    auto skillPoints = GameController::getInstance()->player.getEnemyKillCount();

    for (auto [level, requiredEliminations]: player.getLevelBreakThroughLimits()){
        if ((skillPoints >= requiredEliminations) && (player.getPowerLevel() < level)){
            player.levelUp();
            GameController::getInstance()->unusedSkillPoints++;
        }
    }
}
