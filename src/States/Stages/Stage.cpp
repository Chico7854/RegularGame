#include "States/Stages/Stage.h"

namespace States {
    Stage::Stage(const Texture::ID background, const std::string path, 
                 const float sprite_width, const float sprite_height):
        Ent(background, sprite_width, sprite_height),
        State(Manager::EventManager::getEventManager()),
        pEntityList(nullptr),
        pCollisionManager(Manager::CollisionManager::getCollisionManager()),
        mapPath(path),
        maxYoukais(10),
        points(0)
    {
        setEntityList();
        sf::Font* pointsFont = Manager::GraphicsManager::getGraphicsManager()->getFont(Font::Pixelify);
        if (pointsFont) {
            pointsText.setFont(*pointsFont);
            pointsText.setCharacterSize(24);
            pointsText.setFillColor(sf::Color::White);
            pointsText.setString("Points: 0");
            pointsText.setPosition(10, 10); 
        } else {
            std::cerr << "Failed to load game font.\n";
        }
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

    Entities::Youkai* Stage::createYoukai(const float x, const float y) {
        using namespace Entities;
        Youkai* pYoukai = new Youkai();
        pYoukai->setSpritePosition(x, y);
        pEntityList->append(static_cast<Entity*>(pYoukai)); 
        pCollisionManager->appendEnemy(static_cast<Enemy*>(pYoukai));
        return pYoukai;
    }

    void Stage::createPlatform(const float x, const float y) {
        using namespace Entities;
        Platform* pPlatform1 = new Platform();
        Platform* pPlatform2 = new Platform();
        Platform* pPlatform3 = new Platform();
        Platform* pPlatform4 = new Platform();
        Platform* pPlatform5 = new Platform();
        Platform* pPlatform6 = new Platform();

        pPlatform1->setSpritePosition(x, y);
        pPlatform2->setSpritePosition(x + Constants::SCALE_TXT * 1, y);
        pPlatform3->setSpritePosition(x + Constants::SCALE_TXT * 2, y);
        pPlatform4->setSpritePosition(x + Constants::SCALE_TXT * 3, y);
        pPlatform5->setSpritePosition(x + Constants::SCALE_TXT * 4, y);
        pPlatform6->setSpritePosition(x + Constants::SCALE_TXT * 5, y);

        pEntityList->append(static_cast<Entity*>(pPlatform1));
        pEntityList->append(static_cast<Entity*>(pPlatform2));
        pEntityList->append(static_cast<Entity*>(pPlatform3));
        pEntityList->append(static_cast<Entity*>(pPlatform4));
        pEntityList->append(static_cast<Entity*>(pPlatform5));
        pEntityList->append(static_cast<Entity*>(pPlatform6));

        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform1));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform2));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform3));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform4));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform5));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform6));
    }

    void Stage::createBlock(const float x, const float y) {
        using namespace Entities;
        Platform* pPlatform = new Platform();
        pPlatform->setSpritePosition(x, y);
        pEntityList->append(static_cast<Entity*>(pPlatform));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform));
    }

    void Stage::createPlayer(const float x, const float y) {
        using namespace Entities;
        player = new Player(Texture::Player1, Constants::P1_WIDTH, Constants::P1_HEIGHT);
        player->setSpritePosition(x, y);
        pEntityList->append(static_cast<Entity*>(player));
        Manager::CollisionManager::getCollisionManager()->setPlayer(player);
        player->setStage(this);
    }

    void Stage::updateView() {
        pGraphicsManager->setViewCenter(player->getGlobalHitbox().left);
        sprite.setPosition(pGraphicsManager->getViewPositionX(), 0.f);
    }

    void Stage::updatePointsText(){
        pointsText.setString("Points: " + std::to_string(points));
        pointsText.setPosition(pGraphicsManager->getViewPositionX()+10.f, 10.f);
    }

    void Stage::createMap() {
        pEntityList->clear(); //preventing entities leaking to other stages
        pCollisionManager->clearLists();
        createPlayer(0.f, Constants::FLOOR_HEIGHT - Constants::P1_HEIGHT);
        createEnemies();
        createObstacles();
    }

    void Stage::exec() {
        if(!isPaused) {
            drawBackground();
            checkEnd();
            updateView();
            updatePointsText();
            pCollisionManager->exec();
            pEntityList->execEntities();
            pEntityList->drawEntities();
            pGraphicsManager->draw(pointsText);
        }
    }

    void Stage::setIsPaused(bool isP){
        isPaused = isP;
    }

    void Stage::updatePoints(int p){
        points += p;
    }

    int Stage::getPoints(){
        return points;
    }

    void Stage::checkEnd(){
        const sf::FloatRect p1Coords = player->getGlobalHitbox();
        if ((p1Coords.left + p1Coords.width) > Constants::MAP_WIDTH) {
            States::EndMenu* paused = new States::EndMenu(this);
            pStateStack->pushState(States::StateType::EndMenu, paused, false);
        }
    }

    void Stage::pauseGame(){
        isPaused = true;
        States::PausedState* paused = new States::PausedState(this);
        pStateStack->pushState(States::StateType::Paused, paused, false); 
    }

    void Stage::keyPressed(const sf::Keyboard::Key key){
        if (key == sf::Keyboard::Escape) {
            pauseGame();
        }
    }
}