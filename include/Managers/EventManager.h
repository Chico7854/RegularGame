#pragma once
#include "GraphicsManager.h"
#include "Entities/Characters/Player.h"
using namespace Entities;

namespace Manager {
    class EventManager {
        private:
            GraphicsManager* pGraphicsManager;
            Player* player;

            static EventManager* pSelf;
            EventManager();

        public:
            ~EventManager();
            static EventManager* getEventManager();
            void setPlayer(Player* p);
            void exec();
    };
}