#pragma once
#include "Stage.h"

namespace Stage {
    class DayMountainStage : public Stage {
        public:
            DayMountainStage();
            ~DayMountainStage();

        private:
            void createEnemies();
            void createObstacles();
    };
}