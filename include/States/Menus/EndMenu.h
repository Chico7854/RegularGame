#pragma once
#include "States/State.h"
#include "Managers/EventManager.h"
#include "Event/EventObserver.h"
#include "States/StateStack.h"
#include "States/Menus/MenuState.h"

#include "Utility/Font.h"
#include "Utility/Constants.h"

namespace States {
    enum class EndOptions {
        None = -1,
        SaveScore,
        Menu,
        TotalStates
    };

    class EndMenu : public State{
        private:
            sf::Sprite saveScoreButton;
            sf::Sprite menuButton;
            sf::Text name;
            sf::Text pointsText;
            int points;
            EndOptions selected;
            Stage* pStage;

            void initializeAssets(); 
            void updateSelected();
            void draw();
        public:
            EndMenu(Stage* stage);
            ~EndMenu();

            void exec();
            void keyPressed(const sf::Keyboard::Key key);
    };
}