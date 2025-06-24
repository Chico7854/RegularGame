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
#include "Utility/Font.h"

namespace States {
    class Stage : public Ent, public States::State{
        protected:
            List::EntityList entities;
            Manager::CollisionManager* pCollisionManager;
            Entities::Player* player;
            std::string mapPath;
            sf::Text pointsText;
            const int maxYoukais;
            const bool isSinglePlayer;
            bool isPaused;
            int points;

        public:
            Stage(const Texture::ID background, const std::string path, 
                  const float sprite_width, const float sprite_height, const bool singlePlayer);
            virtual ~Stage();

            const Entities::Player* getPlayer() const;
            void exec();

            void setIsPaused(bool isP);
            void updatePoints(int p);
            int getPoints();
            void checkEnd();
            virtual void save() = 0;
            virtual void loadSave() = 0;

        protected:
            Entities::Youkai* createYoukai(const float x, const float y);
            void createPlatform(const float x, const float y);
            void createBlock(const float x, const float y);
            void createPlayer(const float x, const float y, const bool isPlayer1);
            
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