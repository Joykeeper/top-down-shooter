//
// Created by Admin on 10.06.2024.
//

#include "GameScene.h"
#include "../../GameController.h"
#include "../../Systems/DrawableSystems/PlayerUIDrawingSystem.h"
#include "../../Systems/UpdatableSystems/SceneHandlingSystem.h"

void GameScene::start() {
    GameController::getInstance()->buttonHandler.clear();

    GameController::getInstance()->addUpdatableSystem(new EffectPuttingSystem());
    GameController::getInstance()->addUpdatableSystem(new AuraHandlingSystem());
    GameController::getInstance()->addUpdatableSystem(new InputHandlingSystem());
    GameController::getInstance()->addUpdatableSystem(new WallsCollisionSystem());
    GameController::getInstance()->addUpdatableSystem(new RoomHandlingSystem());
    GameController::getInstance()->addUpdatableSystem(new InteractableHandlingSystem());
    GameController::getInstance()->addUpdatableSystem(new WeaponHandlingSystem());
    GameController::getInstance()->addUpdatableSystem(new EnemyHandlingSystem());
    GameController::getInstance()->addUpdatableSystem(new ProjectileHandlingSystem());
    GameController::getInstance()->addUpdatableSystem(new SpellHandlingSystem());
    GameController::getInstance()->addUpdatableSystem(new EffectRemovingSystem());

    GameController::getInstance()->addDrawableSystem(new CameraMovingSystem());
    GameController::getInstance()->addDrawableSystem(new FieldDrawingSystem());
    GameController::getInstance()->addDrawableSystem(new RoomDrawingSystem());
    GameController::getInstance()->addDrawableSystem(new AuraDrawingSystem());
    GameController::getInstance()->addDrawableSystem(new PlayerDrawingSystem());
    GameController::getInstance()->addDrawableSystem(new EnemyDrawingSystem());
    GameController::getInstance()->addDrawableSystem(new WeaponDrawingSystem());
    GameController::getInstance()->addDrawableSystem(new InteractableDrawingSystem());
    GameController::getInstance()->addDrawableSystem(new ProjectileDrawingSystem());
    GameController::getInstance()->addDrawableSystem(new PlayerUIDrawingSystem());
}
