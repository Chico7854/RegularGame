#pragma once
#include "GraphicsManager.h"
#include "Entities/Characters/Player.h"
#include "Entities/EntityList.h"

namespace Manager {
    class EventManager {
        private:
            GraphicsManager* pGraphicsManager;
            sf::Clock clock;
            EntityList entList;
            Entities::Player* player;

            static EventManager* pSelf;
            EventManager();

        public:
            ~EventManager();
            static EventManager* getEventManager();
            void setEntity(Entities::Entity* ent);
            void setPlayer(Entities::Player* p);

            void keyboardEvent();
            void exec();
    };
}