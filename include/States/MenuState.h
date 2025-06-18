#pragma once
#include "Managers/GraphicsManager.h"
#include "States/State.h"
#include "States/DayState.h"
#include "States/NightState.h"
#include "Event/EventObserver.h"
#include "Stage/Stage.h"
#include "Stage/DayMountainStage.h"
#include "Stage/NightMountainStage.h"
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