#include "Managers/EventManager.h"
#include "Utility/List.h"
#include "Utility/Constants.h"

namespace Manager {
    EventManager* EventManager::pSelf(nullptr);

    EventManager::EventManager():
        pGraphicsManager(GraphicsManager::getGraphicsManager()),
        pCollisionManager(CollisionManager::getCollisionManager()),
        entList(),
        platform()
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

    void EventManager::setPlatform(Entities::Platform* p) {
        platform = p;
    }

    void EventManager::setFloor(Entities::Platform* f) {
        floor = f;
    }

    void EventManager::setBall(Entities::Projectile* b) {
        ball = b;
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