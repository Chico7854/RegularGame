#include "States/NightState.h"

namespace States {
    NightState::NightState(Stage::NightMountainStage* s):
        nightMountainStage(s)
    {}

    NightState::~NightState() {}

    void NightState::exec() {
        nightMountainStage->exec();
    }
}