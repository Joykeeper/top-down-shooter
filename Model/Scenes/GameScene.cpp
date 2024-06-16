//
// Created by Admin on 10.06.2024.
//

#include "GameScene.h"
#include "../../GameController.h"
#include "../../Systems/DrawableSystems/PlayerUIDrawingSystem.h"
#include "../../Systems/UpdatableSystems/SceneHandlingSystem.h"
#include "../../Systems/UpdatableSystems/LevelHandlingSystem.h"
#include "../../Systems/UpdatableSystems/SkillPointsHandlingSystem.h"
#include "../../Systems/UpdatableSystems/PlayerSkillHandlingSystem.h"
#include "../../Systems/UpdatableSystems/EffectPuttingSystem.h"
#include "../../Systems/UpdatableSystems/AuraHandlingSystem.h"
#include "../../Systems/UpdatableSystems/InputHandlingSystem.h"
#include "../../Systems/UpdatableSystems/WallsCollisionSystem.h"
#include "../../Systems/UpdatableSystems/RoomHandlingSystem.h"
#include "../../Systems/UpdatableSystems/InteractableHandlingSystem.h"
#include "../../Systems/UpdatableSystems/WeaponHandlingSystem.h"
#include "../../Systems/UpdatableSystems/EnemyHandlingSystem.h"
#include "../../Systems/UpdatableSystems/ProjectileHandlingSystem.h"
#include "../../Systems/UpdatableSystems/EffectRemovingSystem.h"
#include "../../Systems/UpdatableSystems/SpellHandlingSystem.h"
#include "../../Systems/DrawableSystems/CameraMovingSystem.h"
#include "../../Systems/DrawableSystems/FieldDrawingSystem.h"
#include "../../Systems/DrawableSystems/RoomDrawingSystem.h"
#include "../../Systems/DrawableSystems/PlayerDrawingSystem.h"
#include "../../Systems/DrawableSystems/EnemyDrawingSystem.h"
#include "../../Systems/DrawableSystems/WeaponDrawingSystem.h"
#include "../../Systems/DrawableSystems/InteractableDrawingSystem.h"
#include "../../Systems/DrawableSystems/ProjectileDrawingSystem.h"
#include "../../Systems/DrawableSystems/AuraDrawingSystem.h"

void GameScene::start() {

    GameController::getInstance()->addUpdatableSystem(std::make_unique<EffectPuttingSystem>());
    GameController::getInstance()->addUpdatableSystem(std::make_unique<AuraHandlingSystem>());
    GameController::getInstance()->addUpdatableSystem(std::make_unique<InputHandlingSystem>());
    GameController::getInstance()->addUpdatableSystem(std::make_unique<WallsCollisionSystem>());
    GameController::getInstance()->addUpdatableSystem(std::make_unique<RoomHandlingSystem>());
    GameController::getInstance()->addUpdatableSystem(std::make_unique<PlayerSkillHandlingSystem>());
    GameController::getInstance()->addUpdatableSystem(std::make_unique<InteractableHandlingSystem>());
    GameController::getInstance()->addUpdatableSystem(std::make_unique<EnemyHandlingSystem>());
    GameController::getInstance()->addUpdatableSystem(std::make_unique<SkillPointsHandlingSystem>());
    GameController::getInstance()->addUpdatableSystem(std::make_unique<ProjectileHandlingSystem>());
    GameController::getInstance()->addUpdatableSystem(std::make_unique<SpellHandlingSystem>());
    GameController::getInstance()->addUpdatableSystem(std::make_unique<EffectRemovingSystem>());
    GameController::getInstance()->addUpdatableSystem(std::make_unique<LevelHandlingSystem>());

    GameController::getInstance()->addDrawableSystem(std::make_unique<CameraMovingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<FieldDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<RoomDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<AuraDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<PlayerDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<EnemyDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<InteractableDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<ProjectileDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<PlayerUIDrawingSystem>());
}
