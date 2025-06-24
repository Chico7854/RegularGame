#pragma once
#include "States/Stages/Stage.h"
#include "Entities/Obstacles/Spike.h"

namespace States {
    class DayMountainStage : public States::Stage {
        private:
            const int maxCannonheads;

        public:
            DayMountainStage(const bool isSinglePlayer, const bool defaultMap = true, const int pointsValue = 0);
            ~DayMountainStage();

            void save() override;
            void loadSave() override;

        private:
            Entities::Cannonhead* createCannonhead(const float x, const float y);
            void createSpike(const float x, const float y);
            void createEnemies() override;
            void createObstacles() override;
    };
}