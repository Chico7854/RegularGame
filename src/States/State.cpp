#include "States/State.h"

namespace States{
    State::State() :
        pEventManager(Manager::EventManager::getEventManager()),
        pStateStack(States::StateStack::getInstance())
    {
        //pEventManager->attach(this);
    }

    State::~State(){

    }

    void State::setType(StateType tp) {
        type = tp;
    }
}