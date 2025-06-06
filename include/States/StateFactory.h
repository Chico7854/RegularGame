#pragma once
#include "States/State.h"
#include "States/GameState.h"
#include "Stage/Stage.h"
#include "Stage/DayMountainStage.h"
#include "Stage/NightMountainStage.h"

namespace States {
    class StateFactory {
        public:
            StateFactory();
            ~StateFactory();

            State* createState(const States::StateType id);

        private:
            State* createGameDayState();
            State* createGameNightState();
    };
}