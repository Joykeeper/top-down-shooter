//
// Created by Admin on 10.05.2024.
//

#include "Interactable.h"

float Interactable::getInteractingRadius() const {
    return this->interactingRadius_;
}

bool Interactable::isToDelete() {
    return this->toDelete_;
}
