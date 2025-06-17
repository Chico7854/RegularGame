#include "States/DayState.h"

namespace States {
    DayState::DayState(Stage::DayMountainStage* s):
        dayMountainStage(s)
    {}

    DayState::~DayState() {}

    void DayState::exec() {
        dayMountainStage->exec();
    }
}