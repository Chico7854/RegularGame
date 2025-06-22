#pragma once
#include "States/State.h"
#include "Managers/EventManager.h"
#include "Event/EventObserver.h"
#include "States/StateStack.h"
#include "States/Menus/MenuState.h"

namespace States {
    enum class PausedOptions {
        None = -1,
        Continue,
        Menu,
        SaveGame,
        TotalStates
    };

    class Stage;

    class PausedState : public State{
        private:
            sf::Sprite continueButton;
            sf::Sprite menuButton;
            sf::Sprite saveGameButton;
            PausedOptions selected;
            Stage* pStage;

            void initializeAssets(); 
            void updateSelected();
            void draw();
        public:
            PausedState(Stage* stage);
            ~PausedState();

            void exec();
            void keyPressed(const sf::Keyboard::Key key);
    };
}