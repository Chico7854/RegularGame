#pragma once
#include "State.h"
#include "Stage/Stage.h"
#include "Stage/NightMountainStage.h"

namespace States {
    class NightState : public State {
        private:
            Stage::NightMountainStage* nightMountainStage;

        public:
            NightState(Stage::NightMountainStage* s);
            ~NightState();

            void exec();
            void keyPressed(const sf::Keyboard::Key key) {}
    };
}