//
// Created by Admin on 13.06.2024.
//

#include "GateToNextLevel.h"
#include "../../GameController.h"

void GateToNextLevel::interact(Player &player) {
    GameController::getInstance()->currentLevel->setCompleted(true);
    GameController::getInstance()->levelsCompleted++;
}
