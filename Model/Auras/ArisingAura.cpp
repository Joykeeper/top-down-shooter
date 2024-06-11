//
// Created by Admin on 11.06.2024.
//

#include "ArisingAura.h"
#include "../../GameController.h"

void ArisingAura::actionOnEnd() {
    auto arisen = std::make_unique<PistolEnemy>(getPosition());
    GameController::getInstance()->enemiesToAdd.add(std::move(arisen));

}
