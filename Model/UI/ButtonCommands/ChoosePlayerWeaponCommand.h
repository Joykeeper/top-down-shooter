#pragma once

#include "ButtonCommand.h"
#include "../../Weapons/WeaponType.h"

class ChoosePlayerWeaponCommand : public ButtonCommand {
    WeaponType weaponType;
public:
    ChoosePlayerWeaponCommand(WeaponType weaponType):weaponType(weaponType){};
    void fire() override;
};


