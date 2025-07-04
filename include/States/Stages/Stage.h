#pragma once
#include <fstream>
#include <string>

#include "Ent.h"
#include "States/State.h"
#include "Entities/EntityList.h"
#include "Entities/Characters/Youkai.h"
#include "Entities/Characters/Cannonhead.h"
#include "Entities/Characters/Ghost.h"
#include "Managers/CollisionManager.h"
#include "Managers/EventManager.h"
#include "States/StateStack.h"
#include "States/Menus/PausedState.h"
#include "States/Menus/EndMenu.h"
#include "States/Menus/GameOver.h"
#include "Utility/Font.h"

namespace States {
    class Stage : public Ent, public States::State{
        protected:
            int mapId;
            List::EntityList entities;
            Manager::CollisionManager* pCollisionManager;
            Entities::Player* player1;
            Entities::Player* player2;
            std::string mapPath;
            sf::Text pointsText;
            const int maxYoukais;
            const int maxPlatforms;
            const bool isSinglePlayer;
            int points;

        public:
            Stage(const Texture::ID background, const std::string path, 
                  const float sprite_width, const float sprite_height, const bool singlePlayer, const int pointsValue, const int map);
            virtual ~Stage();

            const int getMapId() const;
            const Entities::Player* getPlayer() const;
            
            void exec();

            void updatePoints(int p);
            int getPoints();
            void checkAlive();
            void checkEnd();
            virtual void save() = 0;
            virtual void loadSave() = 0;

        protected:
            Entities::Youkai* createYoukai(const float x, const float y);
            void createPlatform(const float x, const float y);
            void createBlock(const float x, const float y);
            Entities::Player* createPlayer(const float x, const float y, const bool isPlayer1);
            
            void updateView();
            void updatePointsText();

            virtual void createEnemies() = 0;
            virtual void createObstacles() = 0;
            virtual void createMap();

            void drawBackground();

            void pauseGame();
            void keyPressed(const sf::Keyboard::Key key);
    };
}