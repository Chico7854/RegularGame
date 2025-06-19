#include "States/Stage.h"

namespace States {
    Stage::Stage(const Texture::ID background, const std::string path, const float sprite_width, const float sprite_height):
        Ent(background, sprite_width, sprite_height),
        pEntityList(nullptr),
        pCollisionManager(Manager::CollisionManager::getCollisionManager()),
        mapPath(path),
        maxEnemies(10)
    {
        setEntityList();
        numberOfYoukais = rand() % (maxEnemies - 3);
        numberOfYoukais += 3;
    }

    Stage::~Stage() {}

    const Entities::Player* Stage::getPlayer() const {
        return player;
    }

    void Stage::setEntityList(){
        pEntityList = List::EntityList::getEntityList();
    }

    void Stage::drawBackground() {
        draw();
    }

    void Stage::createYoukai(const float x, const float y) {
        using namespace Entities;
        Youkai* pYoukai = new Youkai();
        pYoukai->setSpritePosition(x, y);
        pEntityList->append(static_cast<Entity*>(pYoukai)); 
        pCollisionManager->appendEnemy(static_cast<Enemy*>(pYoukai));
    }

    void Stage::createPlatform(const float x, const float y) {
        using namespace Entities;
        Platform* pPlatform1 = new Platform();
        Platform* pPlatform2 = new Platform();
        Platform* pPlatform3 = new Platform();
        Platform* pPlatform4 = new Platform();
        Platform* pPlatform5 = new Platform();

        pPlatform1->setSpritePosition(x, y);
        pPlatform2->setSpritePosition(x + Constants::SCALE_TXT * 1, y);
        pPlatform3->setSpritePosition(x + Constants::SCALE_TXT * 2, y);
        pPlatform4->setSpritePosition(x + Constants::SCALE_TXT * 3, y);
        pPlatform5->setSpritePosition(x + Constants::SCALE_TXT * 4, y);

        pEntityList->append(static_cast<Entity*>(pPlatform1));
        pEntityList->append(static_cast<Entity*>(pPlatform2));
        pEntityList->append(static_cast<Entity*>(pPlatform3));
        pEntityList->append(static_cast<Entity*>(pPlatform4));
        pEntityList->append(static_cast<Entity*>(pPlatform5));

        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform1));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform2));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform3));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform4));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform5));
    }

    void Stage::createBlock(const float x, const float y) {
        using namespace Entities;
        Platform* pPlatform = new Platform();
        pPlatform->setSpritePosition(x, y);
        pEntityList->append(static_cast<Entity*>(pPlatform));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform));
    }

    void Stage::createPlayer() {
        using namespace Entities;
        player = new Player(Texture::Player1, Constants::P1_WIDTH, Constants::P1_HEIGHT);
        player->setSpritePosition(0.f, Constants::FLOOR_HEIGHT - Constants::P1_HEIGHT);
        pEntityList->append(static_cast<Entity*>(player));
        Manager::CollisionManager::getCollisionManager()->setPlayer(player);
    }

    void Stage::updateView() {
        pGraphicsManager->setViewCenter(player->getGlobalHitbox().left);
        sprite.setPosition(pGraphicsManager->getViewPositionX(), 0.f);
    }

    void Stage::createMap() {
        createEnemies();
        createObstacles();
        createPlayer();
    }

    void Stage::exec() {
        updateView();
        pEntityList->execEntities();
        pCollisionManager->exec();
        drawBackground();
        pEntityList->drawEntities();
    }
}