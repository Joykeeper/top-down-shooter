//
// Created by Admin on 05.05.2024.
//

#include "Weapon.h"
#include "../Magicball.h"
#include "../Spells/AriseSpell.h"
#include "../../GameController.h"
#include "../../Utils.h"
#include "../Effects/MoveSpeedEffect.h"
#include "../Spells/ASPDBuff.h"
#include "../Spells/MSPDBuff.h"
#include "../Spells/BurningBallSpell.h"
#include "../Effects/BurningMagicBalls.h"
#include "../Effects/WaterConcentration.h"
#include "../Spells/PieceOfHell.h"
#include "../Effects/TraceLeavingEffect.h"


float Weapon::getShootingCooldown() const {
    return this->shootingCooldown;
}

void Weapon::setShootingCooldown(float amount) {
    this->shootingCooldown = amount;
}


std::unique_ptr<Magicball> Weapon::shootProjectile(sf::Vector2f direction) {
    setTimeFromLastShot(0);
    return std::make_unique<Magicball>(this->position_, direction, this->allyOrEnemy_);
}

float Weapon::getTimeFromLastShot() const {
    return this->timeFromLastShot_;
}

void Weapon::setTimeFromLastShot(float time) {
    this->timeFromLastShot_ = time;
}

std::vector<std::unique_ptr<Spell>> Weapon::generateActiveSkills(int amount, WeaponType weaponType) {
    if (amount <= 0) return std::move(std::vector<std::unique_ptr<Spell>>());

    auto& player = GameController::getInstance()->player;
    auto generatedSkills = std::vector<std::unique_ptr<Spell>>();

    if (weaponType == WeaponType::FIRE_STAFF){
        std::cout << "fire\n";
        auto possibleSkills = std::vector<std::unique_ptr<Spell>>();
        possibleSkills.push_back(std::make_unique<ASPDBuff>(&player, 0.07));
        possibleSkills.push_back(std::make_unique<Sunstrike>(&player));
        possibleSkills.push_back(std::make_unique<PieceOfHell>(&player));

        for (auto i = 0; i < amount; i++){
            auto randomSkill = Utils::generateNumberInRange(0, possibleSkills.size());
            generatedSkills.push_back(std::move(possibleSkills[randomSkill]));
            possibleSkills.erase(possibleSkills.begin() + randomSkill);
        }

    } else if (weaponType == WeaponType::WATER_STAFF){
        std::cout << "water\n";
        std::cout << amount << "\n";

        auto possibleSkills = std::vector<std::unique_ptr<Spell>>();
        possibleSkills.push_back(std::make_unique<MSPDBuff>(&player, 1000));
        possibleSkills.push_back(std::make_unique<ASPDBuff>(&player, 0.08));
        possibleSkills.push_back(std::make_unique<AriseSpell>(&player));

        for (auto i = 0; i < amount; i++){
            auto randomSkill = Utils::generateNumberInRange(0, possibleSkills.size());
            generatedSkills.push_back(std::move(possibleSkills[randomSkill]));
            possibleSkills.erase(possibleSkills.begin() + randomSkill);
        }

    }

    return std::move(generatedSkills);
}

std::vector<std::unique_ptr<Effect>> Weapon::generatePassiveSkills(int amount, WeaponType weaponType) {
    if (amount <= 0) return std::move(std::vector<std::unique_ptr<Effect>>());

    auto& player = GameController::getInstance()->player;

    auto generatedSkills = std::vector<std::unique_ptr<Effect>>();

    if (weaponType == WeaponType::FIRE_STAFF){
        auto possibleSkills = std::vector<std::unique_ptr<Effect>>();
        possibleSkills.push_back(std::make_unique<TraceLeavingEffect>(50, 1, 0.3, 3));
        possibleSkills.push_back(std::make_unique<MoveSpeedEffect>(800, 5));
        possibleSkills.push_back(std::make_unique<AttackSpeedEffect>(0.4, 3));

        for (auto i = 0; i < amount; i++){
            auto randomSkill = Utils::generateNumberInRange(0, possibleSkills.size());
            generatedSkills.push_back(std::move(possibleSkills[randomSkill]));
            possibleSkills.erase(possibleSkills.begin() + randomSkill);
        }

    } else if (weaponType == WeaponType::WATER_STAFF){
        auto possibleSkills = std::vector<std::unique_ptr<Effect>>();
        possibleSkills.push_back(std::make_unique<WaterConcentration>(5));
        possibleSkills.push_back(std::make_unique<MoveSpeedEffect>(800, 5));
        possibleSkills.push_back(std::make_unique<AttackSpeedEffect>(0.05, 3));

        for (auto i = 0; i < amount; i++){
            auto randomSkill = Utils::generateNumberInRange(0, possibleSkills.size());
            generatedSkills.push_back(std::move(possibleSkills[randomSkill]));
            possibleSkills.erase(possibleSkills.begin() + randomSkill);
        }

    }

    return std::move(generatedSkills);
}
