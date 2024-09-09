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

    auto texture = sf::Texture();
    if (!texture.loadFromFile("assets/summoningEffect.png"))
    {
        std::cout << "Couldn't load image";
    }

    for (auto undeadPos: undeadsPos){

        auto pos = room->getPos() + undeadPos + sf::Vector2f(150, 150);

        auto graveyardRadius = 40;
        auto graveyard = std::make_unique<ArisingAura>(pos, graveyardRadius, caster);
        auto warning = std::make_unique<WarningAura>(pos, graveyardRadius, 2, COOL_DOWN,
                                                     caster, caster->getAllyOrEnemy(), std::move(graveyard));

        warning->getAnimationHandler() = AnimationHandler(texture, sf::Vector2i (32, 32),
                                                          sf::Vector2f (graveyardRadius/16, graveyardRadius/16), 8);

        warning->getAnimationHandler().createAnimation("default", std::pair<sf::Vector2i,sf::Vector2i>(
                sf::Vector2i(0,0),
                sf::Vector2i(2, 0))
        );
        warning->getAnimationHandler().setAnimation("default");

        GameController::getInstance()->aurasToAdd.add(std::move(warning));
    }
}