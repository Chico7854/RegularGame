#pragma once
#include "Stage.h"
#include "Entities/Obstacles/Spike.h"
#include "Entities/Obstacles/Saw.h"

namespace States {
    class DayMountainStage : public Stage {
        private:
            int numberOfCannonheads;

        public:
            DayMountainStage();
            ~DayMountainStage();

        private:
            void createCannonhead(const float x, const float y);
            void createSpike(const float x, const float y);
            void createSaw(const float x, const float y);
            void createEnemies() override;
            void createObstacles() override;
    };
}