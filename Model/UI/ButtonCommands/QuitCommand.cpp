//
// Created by Admin on 09.06.2024.
//

#include "QuitCommand.h"
#include "../../../GameController.h"

void QuitCommand::fire() {
    GameController::getInstance()->window->close();
    std::cout << "Quit game" << " \n";
}
