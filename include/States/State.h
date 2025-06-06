#pragma once

namespace States {
    enum class StateType {
        None = -1,
        GameDay,
        GameNight
    };

    class State {
        public:
            virtual void exec() = 0;
    };
}