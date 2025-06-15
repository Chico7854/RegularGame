#include "Managers/StateManager.h"

namespace Manager {
    StateManager* StateManager::pSelf(nullptr);

    StateManager::StateManager():
        statesStack()
    {}

    StateManager::~StateManager() {
        pSelf = nullptr;
    }

    StateManager* StateManager::getStateManager() {
        if (pSelf == nullptr) {
            pSelf = new StateManager();
        }
        return pSelf;
    }

    // void StateManager::addState(const States::StateType id) {
    //     States::State* state = stateFactory.createState(id);
    //     if (state == nullptr) {
    //         std::cerr << "ERROR: Couldn't create state.\n";
    //     }
    //     statesStack.push(state);
    // }

    void StateManager::removeState() {
        if (statesStack.top()) {
            delete (statesStack.top());
            statesStack.top() = nullptr;
            statesStack.pop();
        }
        if (statesStack.empty()) {
            GraphicsManager* pGraphicsManager = GraphicsManager::getGraphicsManager();
            pGraphicsManager->closeWindow();
        }
    }

    void StateManager::exec() {
        if (!statesStack.empty()) {
            statesStack.top()->exec();
        }
    }

    States::State* StateManager::getState() const{
        return statesStack.top();
    }
}