#pragma once
#include "States/Stages/Stage.h"
#include "Entities/Obstacles/Spike.h"

namespace States {
    class DayMountainStage : public States::Stage {
        private:
            const int maxCannonheads;

        public:
            DayMountainStage();
            ~DayMountainStage();

        private:
            void createCannonhead(const float x, const float y);
            void createSpike(const float x, const float y);
            void createEnemies() override;
            void createObstacles() override;
    };
}