#pragma once
#include "Managers/EventManager.h"
#include "Event/EventObserver.h"
#include "States/StateStack.h"

namespace States {
    enum class StateType {
        None = -1,
        Menu,
        GameDay,
        GameNight,
        TotalStates
    };

    class State {
        protected:
            Manager::GraphicsManager* pGraphicsManager;
            Manager::EventManager* pEventManager;
            States::StateStack* pStateStack;
        public:
            State();
            virtual ~State();

            virtual void exec() = 0;
            virtual void keyPressed(const sf::Keyboard::Key key) {}
            virtual void keyReleased(const sf::Keyboard::Key key) {}
            virtual void textEntered(const char character) {}
            virtual void setIsActive(bool) {}
    };
}