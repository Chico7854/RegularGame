#pragma once
#include "Managers/GraphicsManager.h"
#include "States/State.h"
#include "Event/EventObserver.h"
#include "States/Stage.h"
#include "States/DayMountainStage.h"
#include "States/NightMountainStage.h"
#include <SFML/Graphics.hpp>

namespace States {
    enum class Options {
        NewDay,
        NewNight,
        ExitGame
    };

    class MenuState : public State, public Event::EventObserver {
        private:
            sf::Sprite newDayButton;
            sf::Sprite newNightButton;
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
            void setIsActive(bool isA) override;
    };
}