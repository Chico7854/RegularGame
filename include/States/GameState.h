#pragma once
#include "State.h"
#include "Stage/Stage.h"

namespace States {
    class GameState : public State {
        private:
            Stage::Stage* stage;

        public:
            GameState(Stage::Stage* s);
            ~GameState();

            void exec();
    };
}