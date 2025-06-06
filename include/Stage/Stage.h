#pragma once
#include <fstream>

#include "Ent.h"
#include "Entities/EntityList.h"
#include "Entities/Characters/Youkai.h"
#include "Entities/Characters/Cannonhead.h"
#include "Entities/EntityFactory.h"
#include "Managers/CollisionManager.h"
#include "Managers/EventManager.h"

namespace Stage {
    class Stage : public Ent {
        protected:
            List::EntityList charactersList;
            List::EntityList obstaclesList;
            Entities::EntityFactory entityFactory;
            Manager::CollisionManager* pCollisionManager;
            Entities::Player* player;

        public:
            Stage(const Texture::ID background);
            ~Stage();

            const Entities::Player* getPlayer() const;

        protected:
            void createEntity(const char ent, const sf::Vector2i pos);
            void createCharacter(const Entities::EntityType type, const float x, const float y);
            void createObstacle(const Entities::EntityType type, const float x, const float y);
            void createPlayer();
            void updateView();

            // virtual void createEnemies() = 0;
            // virtual void createObstacle() = 0;

        public:
            virtual void createMap();
            void exec();
    };
}