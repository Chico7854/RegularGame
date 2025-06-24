#pragma once
#include "States/State.h"
#include "Managers/EventManager.h"
#include "Event/EventObserver.h"
#include "States/StateStack.h"
#include "States/Menus/MenuState.h"

#include "Utility/Font.h"
#include "Utility/Constants.h"

namespace States {
    class GameOver : public State {
        private:
            sf::Sprite menuButton;
            sf::Text gameOverText;

            void initializeAssets();
            void draw();
        public:
            GameOver();
            ~GameOver();

            void exec();
            void keyPressed(const sf::Keyboard::Key key);
    };
}