#pragma once


#include "ButtonCommand.h"
#include "../../Scenes/Scene.h"
#include <memory>

class ChangeSceneCommand : public ButtonCommand {
    std::unique_ptr<Scene> newScene;
public:
    ChangeSceneCommand(std::unique_ptr<Scene> scene): newScene(std::move(scene)){};
    void fire() override;
};
