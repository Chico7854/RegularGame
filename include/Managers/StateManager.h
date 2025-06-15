#pragma once
#include <stack>
#include <iostream>

#include "States/State.h"
#include "Managers/GraphicsManager.h"

namespace Manager {
    class StateManager {
        private:
            std::stack<States::State*> statesStack;

            static StateManager* pSelf;
            StateManager();

        public:
            ~StateManager();
            static StateManager* getStateManager();

            void exec();
            // void addState(const States::StateType id);
            void removeState();
            States::State* getState() const;
    };
}