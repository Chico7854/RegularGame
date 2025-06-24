#pragma once
#include "States/State.h"
#include "Managers/EventManager.h"
#include "Event/EventObserver.h"
#include "States/StateStack.h"
#include "States/Menus/MenuState.h"

#include "Utility/Font.h"
#include "Utility/Constants.h"

namespace States{
    class Stage;
}

namespace States {
    enum class EndOptions {
        None = -1,
        SaveScore,
        Menu,
        NextStage,
        TotalStates
    };

    class EndMenu : public State{
        private:
            sf::Sprite saveScoreButton;
            sf::Sprite menuButton;
            sf::Sprite nextStageButton;

            sf::Text nameText;
            std::string playerName; 
            bool nameInputActive;

            sf::Text pointsText;
            int points;

            EndOptions selected;
            Stage* pStage;

            void initializeAssets(); 
            void updateSelected();
            void draw();

            void saveOnTxt();
        public:
            EndMenu(Stage* stage);
            ~EndMenu();

            void exec();
            void keyPressed(const sf::Keyboard::Key key);
            void textEntered(const sf::Uint32 unicode);
    };
}