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

    void EventManager::keyboardEvent() {
        /*Player 1*/
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player->setDx(player->getSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player->setDx(-(player->getSpeed()));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player->getOnGround()) {
            player->setDy(Constants::JUMP_SPEED);
        }

        /*Player 2*/
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        //     dx = speed;
        // }

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        //     dx = -speed;
        // }

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && getOnGround()) {
        //     dy = -speed * 1.3;
        // }
    }

    void EventManager::exec() {
        sf::Event event;
        while (pGraphicsManager->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                pGraphicsManager->closeWindow();
            }
        }

        /*Drawing entities*/
        //THIS SHOULD NOT BE HERE, ITS NOT THE JOB OF EVENTMANAGER TO DO THIS, NEED TO FIX LATER
        if (!player->getIsHurt()) {
            keyboardEvent();
        }
        player->update();
        entList.updateEntities();
        pCollisionManager->applyNoDamageCollision(player, floor);
        pCollisionManager->applyDamageCollision(player, platform);
        player->draw();
        entList.drawEntities();
    }
}