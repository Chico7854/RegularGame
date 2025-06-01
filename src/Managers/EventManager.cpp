#include "Managers/EventManager.h"

namespace Manager {
    EventManager* EventManager::pSelf(nullptr);

    EventManager::EventManager():
        pGraphicsManager(GraphicsManager::getGraphicsManager()),
        player(nullptr)
    {}

    EventManager::~EventManager() {
        if (pSelf) {
            delete pSelf;
        }
    }

    void EventManager::setPlayer(Player* p) {
        player = p;
    }

    void exec() {
        
    }
}