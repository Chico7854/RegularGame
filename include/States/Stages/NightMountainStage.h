#pragma once
#include "States/Stages/Stage.h"
#include "Entities/Obstacles/Saw.h"

namespace States {
    class NightMountainStage : public States::Stage {
        private:
            const int maxGhosts;

        public:
            NightMountainStage();
            ~NightMountainStage();

        private:
            void createGhost(const float x, const float y);
            void createSaw(const float x, const float y);
            void createEnemies() override;
            void createObstacles() override;
    };
}