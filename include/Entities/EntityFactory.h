#pragma once
#include "Entity.h"
#include "Characters/Youkai.h"
#include "Characters/Cannonhead.h"
#include "Obstacles/Obstacle.h"
#include "Obstacles/Platform.h"
#include "Obstacles/MediumObstacle.h"
#include "Obstacles/HardObstacle.h"

namespace Entities {
    class EntityFactory {
        public:
            EntityFactory();
            ~EntityFactory();

            Entity* createEntity(const EntityType type, const float x, const float y);

        private:
            Entity* createYoukai(const float x, const float y);
            Entity* createCannonhead(const float x, const float y);

            Entity* createPlatform(const float x, const float y);
            Entity* createSpike(const float x, const float y);
            Entity* createSaw(const float x, const float y);
            Entity* createFloor(const float x);
            Entity* createPlayer();
    };
}