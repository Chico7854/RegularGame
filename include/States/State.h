#pragma once
#include "Managers/EventManager.h"
#include "Event/EventObserver.h"
#include "States/StateStack.h"

namespace States {
    enum class StateType {
        None = -1,
        Menu,
        Paused,
        LoadGame,
        GameDay,
        GameNight,
        EndMenu,
        Leaderboard,
        GameOver,
        TotalStates
    };

    class State : public Event::EventObserver{
        protected:
            StateType type;
            Manager::EventManager* pEventManager;
            States::StateStack* pStateStack;
            
        public:
            State(Event::EventSubject* pES);
            virtual ~State();

            virtual void exec() = 0;
            virtual void keyPressed(const sf::Keyboard::Key key) {}
            virtual void textEntered(const sf::Uint32 unicode) {}
            void setType(StateType type);
    };
}