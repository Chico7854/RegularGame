#pragma once
#include "State.h"
#include "Stage/Stage.h"
#include "Stage/DayMountainStage.h"

namespace States {
    class DayState : public State , public Event::EventObserver{
        private:
            Stage::DayMountainStage* dayMountainStage;

        public:
            DayState(Stage::DayMountainStage* s);
            ~DayState();

            void exec();
            void keyPressed(const sf::Keyboard::Key key) {}
    };
}