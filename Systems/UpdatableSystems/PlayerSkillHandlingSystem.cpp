//
// Created by Admin on 16.06.2024.
//

#include "PlayerSkillHandlingSystem.h"
#include "../../GameController.h"

void PlayerSkillHandlingSystem::update(sf::Time deltaTime) const {
    Player& player = GameController::getInstance()->player;

    if (player.getActiveSkill1()) player.getActiveSkill1()->updateTimeTillNext(deltaTime.asSeconds());
    if (player.getActiveSkill2()) player.getActiveSkill2()->updateTimeTillNext(deltaTime.asSeconds());
}
