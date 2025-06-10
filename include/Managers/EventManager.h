#pragma once
#include "GraphicsManager.h"
#include "CollisionManager.h"
#include "Entities/Characters/Player.h"
#include "Entities/EntityList.h"
#include "Entities/Obstacles/Platform.h"

namespace Manager {
    class EventManager {
        private:
            GraphicsManager* pGraphicsManager;
            CollisionManager* pCollisionManager;
            List::EntityList entList;
            Entities::Player* player;

            static EventManager* pSelf;
            EventManager();

        public:
            ~EventManager();
            static EventManager* getEventManager();
            void setEntity(Entities::Entity* ent);
            void setPlayer(Entities::Player* p);

            void exec();
    };
}