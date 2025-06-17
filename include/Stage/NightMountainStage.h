#pragma once
#include "Stage.h"

namespace Stage {
    class NightMountainStage : public Stage {
        public:
            NightMountainStage();
            ~NightMountainStage();

        private:
            

            void createEnemies() override {};
            void createObstacles() override {}
    };
}