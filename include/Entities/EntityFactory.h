#pragma once
#include "Entity.h"
#include "Obstacles/Obstacle.h"

namespace Entities {
    class EntityFactory {
        public:
            EntityFactory();
            ~EntityFactory();

            Entity* createEntity(EntityType type);

        private:
            Entity* createObstacle(Obstacle::ObstacleType obstacleType);
            Entity* createPlatform();

    };
}