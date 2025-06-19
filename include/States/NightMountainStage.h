#pragma once
#include "Stage.h"
#include "Entities/Obstacles/Saw.h"

namespace States {
    class NightMountainStage : public Stage {
        private:
            int numberOfGhosts;

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