#include "Managers/EventManager.h"
#include "Utility/List.h"

namespace Manager {
    EventManager* EventManager::pSelf(nullptr);

    EventManager::EventManager():
        pGraphicsManager(GraphicsManager::getGraphicsManager()),
        entList()
    {}

    EventManager::~EventManager() {
        if (pSelf) {
            delete pSelf;
        }
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
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        sf::Event event;
        while (pGraphicsManager->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                pGraphicsManager->closeWindow();
            }
        }

        /*Drawing entities*/
        //THIS SHOULD NOT BE HERE, ITS NOT THE JOB OF EVENTMANAGER TO DO THIS, NEED TO FIX LATER
        player->keyboardInput(0);
        player->update(time);
        player->draw();
        // player2.keyboardInput(1);

        entList.updateEntities(time);
        entList.drawEntities();
    }
}