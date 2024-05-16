#include "InteractableHandlingSystem.h"

#include "../../GameController.h"
#include "../../Utils.h"

auto removeToDelete(auto interactables) -> void;
auto checkInteraction(auto interactables, auto characters) -> void;


void InteractableHandlingSystem::update(sf::Time) const {
    auto interactables = GameController::getInstance()->interactableHandler.getItems();
    auto characters = GameController::getInstance()->getCharacters();

    removeToDelete(interactables);

    checkInteraction(interactables, characters);

}

void removeToDelete(auto interactables){
    auto removedInteractable = std::vector<Interactable*>();

    for(auto& interactable: interactables){
        if(interactable->isToDelete()){
            removedInteractable.push_back(interactable);
        }
    }

    for(auto& item: removedInteractable){
        GameController::getInstance()->interactableHandler.remove(*item);
    }
}

void checkInteraction(auto interactables, auto characters){
    for(auto interactable: interactables){
        for (auto& character: characters){
            auto chPos = character->getPos();
            auto intPos = interactable->getPos();
            if (Utils::objectInRadius(*character, interactable->getInteractingRadius(), intPos)){
                interactable->interact(*character);
            }
        }
    }
}
