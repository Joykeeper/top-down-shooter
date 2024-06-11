#pragma once


#include "ButtonCommand.h"

class QuitCommand : public ButtonCommand {
public:
    void fire() override;
};
