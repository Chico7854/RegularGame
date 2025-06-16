#include "States/State.h"

namespace States{
    State::State() : pGraphicsManager(Manager::GraphicsManager::getGraphicsManager()),
        pEventManager(Manager::EventManager::getEventManager()),
        pStateStack(States::StateStack::getInstance())
    {
        //pEventManager->attach(this);
    }

    State::~State(){

    }
}