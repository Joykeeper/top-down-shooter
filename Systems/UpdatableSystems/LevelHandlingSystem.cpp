//
// Created by Admin on 13.06.2024.
//

#include "LevelHandlingSystem.h"
#include "../../GameController.h"

void LevelHandlingSystem::update(sf::Time) const {
    auto& level = GameController::getInstance()->currentLevel;
    if (level->isCompleted()) {
        GameController::getInstance()->interactableHandler.clear();
        GameController::getInstance()->enemyHandler.clear();
        GameController::getInstance()->auraHandler.clear();

        level->generateLevel(5);
        level->setCompleted(false);

        GameController::getInstance()->player.setPosition(level->getPlayerStartPoint());
    }
}
