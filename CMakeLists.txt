cmake_minimum_required(VERSION 3.27)
project(MagicianFest)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(MagicianFest main.cpp
        GameController.cpp
        GameController.h
        Model/Characters/Player.cpp
        Model/Characters/Player.h
        Systems/UpdatableSystems/InputHandlingSystem.cpp
        Systems/UpdatableSystems/InputHandlingSystem.h
        Systems/DrawableSystems/PlayerDrawingSystem.cpp
        Systems/DrawableSystems/PlayerDrawingSystem.h
        Systems/DrawableSystem.h
        Systems/UpdatableSystem.h
        Systems/DrawableSystems/CameraMovingSystem.cpp
        Systems/DrawableSystems/CameraMovingSystem.h
        Systems/DrawableSystems/FieldDrawingSystem.cpp
        Systems/DrawableSystems/FieldDrawingSystem.h
        Model/Magicball.cpp
        Model/Magicball.h
        Model/GameObject.cpp
        Model/GameObject.h
        Systems/DrawableSystems/ProjectileDrawingSystem.cpp
        Systems/DrawableSystems/ProjectileDrawingSystem.h
        Systems/UpdatableSystems/ProjectileHandlingSystem.cpp
        Systems/UpdatableSystems/ProjectileHandlingSystem.h
        Utils.h
        Model/Characters/Enemies/Enemy.cpp
        Model/Characters/Enemies/Enemy.h
        Systems/DrawableSystems/EnemyDrawingSystem.cpp
        Systems/DrawableSystems/EnemyDrawingSystem.h
        Systems/UpdatableSystems/EnemyHandlingSystem.cpp
        Systems/UpdatableSystems/EnemyHandlingSystem.h
        Model/Weapons/Weapon.cpp
        Model/Weapons/Weapon.h
        Model/Characters/Character.cpp
        Model/Characters/Character.h
        Systems/UpdatableSystems/WeaponHandlingSystem.cpp
        Systems/UpdatableSystems/WeaponHandlingSystem.h
        Systems/DrawableSystems/WeaponDrawingSystem.cpp
        Systems/DrawableSystems/WeaponDrawingSystem.h
        Model/AllyOrEnemy.h
        Model/Handler.h
        Model/Room.cpp
        Model/Room.h
        Systems/UpdatableSystems/RoomHandlingSystem.cpp
        Systems/UpdatableSystems/RoomHandlingSystem.h
        Systems/DrawableSystems/RoomDrawingSystem.cpp
        Systems/DrawableSystems/RoomDrawingSystem.h
        Model/Weapons/Pistol.cpp
        Model/Weapons/Pistol.h
        Model/Characters/Enemies/PistolEnemy.cpp
        Model/Characters/Enemies/PistolEnemy.h
)

target_link_libraries(MagicianFest sfml-graphics)

