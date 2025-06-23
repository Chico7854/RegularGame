#pragma once
#include "Managers/GraphicsManager.h"
#include "States/State.h"
#include "Event/EventObserver.h"
#include <SFML/Graphics.hpp>

namespace States {
    class DayMountainStage;
    class NightMountainStage;
}

namespace States {
    enum class MenuOptions {
        NewDay,
        NewNight,
        ExitGame,
        LoadGame,
        GameMode,
        Leaderboard
    };

    class MenuState : public State {
        private:
            sf::Sprite newDayButton;
            sf::Sprite newNightButton;
            sf::Sprite exitGameButton;
            sf::Sprite loadGameButton;
            sf::Sprite leaderboard;
            sf::Sprite singleplayer;
            sf::Sprite multiplayer;
            MenuOptions selected;

            bool isSingle;

            void initializeAssets(); 
            void updateSelected();
            void draw();

        public:
            MenuState();
            ~MenuState();

            void exec() override;
            void keyPressed(const sf::Keyboard::Key key) override;
            void setIsActive(bool isA) override;
    };
}