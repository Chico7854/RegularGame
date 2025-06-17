#pragma once
#include "State.h"
#include "Stage/Stage.h"
#include "Stage/DayMountainStage.h"

namespace States {
    class DayState : public State {
        private:
            Stage::DayMountainStage* dayMountainStage;

        public:
            DayState(Stage::DayMountainStage* s);
            ~DayState();

            void exec();
    };
}