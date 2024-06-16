//
// Created by Admin on 03.05.2024.
//

#include "Enemy.h"
#include "../../Interactables/ShieldPotion.h"
#include "../../../Utils.h"
#include "../../../GameController.h"
#include "../../Interactables/FastPotion.h"
#include "../../Interactables/BerserkPotion.h"

sf::Vector2f Enemy::getNextMove() {
    return movementBehavior->nextMove(position_);
}

Spell &Enemy::getSpell() {
    return *spell;
}

float Enemy::getTimeTillEndOfCast() {
    return timeTillEndOfCast;
}

float Enemy::getCastingTime() {
    return getCastingTime();
}

void Enemy::updateTimeTillEndOfCast(float dtime) {
    timeTillEndOfCast -= dtime;
    if (timeTillEndOfCast < 0) timeTillEndOfCast = 0;
}

std::unique_ptr<Interactable> Enemy::provideInteractableOnDeath() {
    if (!interactableOnElimination) return nullptr;
    interactableOnElimination->move(position_-interactableOnElimination->getPos());
    return std::move(interactableOnElimination);
}

void Enemy::chooseInteractableOnDeath() {
    auto interactable = Utils::generateNumberInRange(0, 12);

    if (interactable < 7){
        interactableOnElimination = nullptr;
    } else if (interactable == 7){
        interactableOnElimination = std::make_unique<HealingSalve>(position_, 10);
    } else if (interactable == 8){
        interactableOnElimination = std::make_unique<ShieldPotion>(position_, 10);
    } else if (interactable == 9){
        interactableOnElimination = std::make_unique<HealingSalve>(position_, 10);
    } else if (interactable == 10){
        interactableOnElimination = std::make_unique<FastPotion>(position_, 1000);
    } else if (interactable == 11){
        interactableOnElimination = std::make_unique<BerserkPotion>(position_, 0.07);
    }
}

Enemy::Enemy(sf::Vector2f pos, int health, std::unique_ptr<Spell> spell, float moveSpeed, sf::Color color, float castingTime,
             std::unique_ptr<MovementBehavior> movementBehavior) :
        Character(pos, sf::Vector2f(80, 80), health+health*GameController::getInstance()->levelsCompleted, moveSpeed, AllyOrEnemy::ENEMY),
        movementBehavior(std::move(movementBehavior)),
        spell(std::move(spell)), CASTING_TIME(castingTime), timeTillEndOfCast(0), color(color){

    chooseInteractableOnDeath();

}

sf::Color Enemy::getColor() {
    return color;
};

