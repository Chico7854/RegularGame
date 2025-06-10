#include "Managers/EventManager.h"
#include "Utility/List.h"
#include "Utility/Constants.h"

namespace Manager {
    EventManager* EventManager::pSelf(nullptr);

    EventManager::EventManager():
        pGraphicsManager(GraphicsManager::getGraphicsManager()),
        pCollisionManager(CollisionManager::getCollisionManager()),
        entList()
    {}

    EventManager::~EventManager() {
    }

    EventManager* EventManager::getEventManager() {
        if (!pSelf) {
            pSelf = new EventManager();
        }
        return pSelf;
    }

    void EventManager::setEntity(Entities::Entity* ent) {
        if (ent) {
            entList.append(ent);
        }
    }

    void EventManager::setPlayer(Entities::Player* p) {
        if (p) {
            player = p;
        }
    }
    
    void EventManager::exec() {
        sf::Event event;
        while (pGraphicsManager->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                pGraphicsManager->closeWindow();
            }
        }
    }
}