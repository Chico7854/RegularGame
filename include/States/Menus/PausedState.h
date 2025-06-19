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

    class PausedState{
        private:
            Options selected;

        public:
            PausedState();
            ~PausedState();

            void exec();
            void keyPressed(const sf::Keyboard::Key key);
    };
}