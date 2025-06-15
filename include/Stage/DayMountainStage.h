#pragma once
#include "Stage.h"

namespace Stage {
    class DayMountainStage : public Stage {
        private:
            int numberOfCannonheads;

        public:
            DayMountainStage();
            ~DayMountainStage();

        private:
            void createCannonhead(const float x, const float y);
            void createEnemies() override;
            void createObstacles() override;
    };
}