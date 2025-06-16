#pragma once
#include "Managers/GraphicsManager.h"
#include "States/State.h"
#include "States/GameState.h"
#include "Event/EventObserver.h"
#include "Stage/Stage.h"
#include "Stage/DayMountainStage.h"
#include <SFML/Graphics.hpp>

namespace States {
    enum class Options {
        NewGame,
        ExitGame
    };

    class MenuState : public State, public Event::EventObserver {
        private:
            sf::Sprite newGameButton;
            sf::Sprite exitGameButton;
            Options selected;

            void initializeAssets(); 
            void updateSelected();
            void draw();

        public:
            MenuState(Event::EventSubject* pES);
            ~MenuState();

            void exec() override;
            void keyPressed(const sf::Keyboard::Key key) override;
            void keyReleased(const sf::Keyboard::Key key) override;
            void textEntered(const char character) override;
            void setIsActive(bool isA) override;
    };
}