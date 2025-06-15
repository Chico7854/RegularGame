#include "Stage/Stage.h"

namespace Stage {
    Stage::Stage(const Texture::ID background, const std::string path, const float sprite_width, const float sprite_height):
        Ent(background, sprite_width, sprite_height),
        entityList(),
        pCollisionManager(Manager::CollisionManager::getCollisionManager()),
        mapPath(path),
        maxEnemies(10)
    {
        numberOfYoukais = rand() % (maxEnemies - 3);
        numberOfYoukais += 3;
    }

    Stage::~Stage() {}

    const Entities::Player* Stage::getPlayer() const {
        return player;
    }

    void Stage::drawBackground() {
        draw();
    }

    void Stage::createYoukai(const float x, const float y) {
        using namespace Entities;
        Youkai* pYoukai = new Youkai();
        pYoukai->setSpritePosition(x, y);
        entityList.append(static_cast<Entity*>(pYoukai)); 
        pCollisionManager->appendEnemy(static_cast<Enemy*>(pYoukai));
    }

    void Stage::createPlatform(const float x, const float y) {
        using namespace Entities;
        Platform* pPlatform = new Platform(Texture::Platform, Constants::PLATFORM_WIDTH, Constants::PLATFORM_HEIGHT);
        pPlatform->setSpritePosition(x, y);
        entityList.append(static_cast<Entity*>(pPlatform));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform));
    }

    void Stage::createPlayer() {
        using namespace Entities;
        player = new Player(Texture::Player1, Constants::P1_WIDTH, Constants::P1_HEIGHT);
        player->setSpritePosition(0.f, Constants::FLOOR_HEIGHT - Constants::P1_HEIGHT);
        entityList.append(static_cast<Entity*>(player));
        Manager::CollisionManager::getCollisionManager()->setPlayer(player);
    }

    void Stage::updateView() {
        pGraphicsManager->setViewCenter(player->getGlobalHitbox().left);
        setSpritePosition(pGraphicsManager->getViewPositionX(), 0.f);
    }

    void Stage::createMap() {
        createEnemies();
        createObstacles();
        createPlayer();
    }

    void Stage::exec() {
        updateView();
        entityList.execEntities();
        pCollisionManager->verifyCollisions();
        drawBackground();
        entityList.drawEntities();
    }
}