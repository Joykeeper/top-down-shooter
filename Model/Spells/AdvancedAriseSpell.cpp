//
// Created by Admin on 16.06.2024.
//

#include "AdvancedAriseSpell.h"
#include "../../GameController.h"
#include "../../Utils.h"
#include "../Auras/WarningAura.h"
#include "../Auras/ArisingAura.h"

void AdvancedAriseSpell::cast(sf::Vector2f) {
    timeTillNext = COOL_DOWN;

    auto room = GameController::getInstance()->currentLevel->getActiveRoom();

    auto undeadsPos = std::vector<sf::Vector2f>();

    auto amountOfUndead = Utils::generateNumberInRange(5, 8);

    auto roomSize = sf::Vector2f(Room::ROOM_SIZE.x - 300, Room::ROOM_SIZE.y - 300);

    for (auto i = 0; i <amountOfUndead; i++){
        auto x = Utils::generateNumberInRange(0, roomSize.x);
        auto y = Utils::generateNumberInRange(0, roomSize.y);

        undeadsPos.push_back(sf::Vector2f (x, y));
    }

    for (auto undeadPos: undeadsPos){

        auto pos = room->getPos() + undeadPos + sf::Vector2f(150, 150);

        auto graveyardRadius = 40;
        auto graveyard = std::make_unique<ArisingAura>(pos, graveyardRadius, caster);
        auto warning = std::make_unique<WarningAura>(pos, graveyardRadius, 2, COOL_DOWN,
                                                     caster, caster->getAllyOrEnemy(), std::move(graveyard));

        GameController::getInstance()->aurasToAdd.add(std::move(warning));
    }
}