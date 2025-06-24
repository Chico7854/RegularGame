#pragma once
#include "States/Stages/Stage.h"
#include "Entities/Obstacles/Saw.h"

namespace States {
    class NightMountainStage : public States::Stage {
        private:
            const int maxGhosts;

        public:
            NightMountainStage(const bool isSinglePlayer, const bool defaultMap = true, const int pointsValue = 0);
            ~NightMountainStage();

            void save() override;
            void loadSave() override;

        private:
            Entities::Ghost* createGhost(const float x, const float y);
            Entities::Saw* createSaw(const float x, const float y);
            void createEnemies() override;
            void createObstacles() override;
    };
}