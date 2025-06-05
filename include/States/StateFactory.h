#pragma once
#include "States/State.h"
#include "States/GameState.h"
#include "Stage/Stage.h"

namespace States {
    class StateFactory {
        public:
            StateFactory();
            ~StateFactory();

            State* createState(const States::StateType id);

        private:
            State* createGameState();
    };
}