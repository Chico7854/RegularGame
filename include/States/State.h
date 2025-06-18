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
            StateType type;
            Manager::GraphicsManager* pGraphicsManager;
            Manager::EventManager* pEventManager;
            States::StateStack* pStateStack;
            
        public:
            State();
            virtual ~State();

            virtual void exec() = 0;
            virtual void keyPressed(const sf::Keyboard::Key key) {}
            virtual void setIsActive(bool isA) {}
            void setType(StateType type);
    };
}