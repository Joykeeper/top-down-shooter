//
// Created by Admin on 09.06.2024.
//

#include "ButtonHandlingSystem.h"
#include "../../GameController.h"
#include "../../Utils.h"

void ButtonHandlingSystem::update(sf::Time) const {
    auto& buttons = GameController::getInstance()->buttonHandler.getItems();

    for (auto& button: buttons){
        if (Utils::isPointInRect(button->getPosition(), button->getSize(), GameController::getInstance()->getMousePos())){
            button->setSelected(true);
        } else {
            button->setSelected(false);
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        auto& buttons = GameController::getInstance()->buttonHandler.getItems();
        for (auto& button: buttons){
            if (button->isSelected()){
                button->click();
                return;
            }
        }
    }
}
