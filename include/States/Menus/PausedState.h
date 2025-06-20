#pragma once
#include "States/State.h"
#include "Managers/EventManager.h"
#include "Event/EventObserver.h"
#include "States/StateStack.h"

namespace States {
    enum class Options {
        None = -1,
        Continue,
        Menu,
        TotalStates
    };

    class PausedState : public State, public Event::EventObserver{
        private:
            sf::Sprite continueButton;
            sf::Sprite menuButton;
            Options selected;

            void initializeAssets(); 
            void updateSelected();
            void draw();
        public:
            PausedState(Event::EventSubject* pES);
            ~PausedState();

            void exec();
            void keyPressed(const sf::Keyboard::Key key);
    };
}