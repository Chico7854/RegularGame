#pragma once

namespace States {
    enum class StateType {
        None = -1,
        Game
    };

    class State {
        public:
            virtual void exec() = 0;
    };
}