#include "States/Stages/Stage.h"

namespace States {
    Stage::Stage(const Texture::ID background, const std::string path, 
                 const float sprite_width, const float sprite_height, const bool singlePlayer, const int pointsValue, const int map):
        Ent(background, sprite_width, sprite_height),
        State(Manager::EventManager::getEventManager()),
        entities(),
        pCollisionManager(Manager::CollisionManager::getCollisionManager()),
        mapPath(path),
        maxYoukais(10),
        maxPlatforms(30),
        isSinglePlayer(singlePlayer),
        points(pointsValue),
        mapId(map)
    {
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

    Stage::~Stage() {
        pCollisionManager = nullptr;
        player = nullptr;
    }

    const int Stage::getMapId() const {
        return mapId;
    }

    const Entities::Player* Stage::getPlayer() const {
        return player;
    }

    void Stage::drawBackground() {
        draw();
    }

    Entities::Youkai* Stage::createYoukai(const float x, const float y) {
        using namespace Entities;
        try {
            Youkai* pYoukai = new Youkai();
            pYoukai->setSpritePosition(x, y);
            entities.append(static_cast<Entity*>(pYoukai)); 
            pCollisionManager->appendEnemy(static_cast<Enemy*>(pYoukai));
            return pYoukai;
        }
        catch (const std::exception& e) {
            std::cerr << "ERROR Failed to create Youkai: " << e.what() << std::endl;
            exit(1);
        }
        
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

        entities.append(static_cast<Entity*>(pPlatform1));
        entities.append(static_cast<Entity*>(pPlatform2));
        entities.append(static_cast<Entity*>(pPlatform3));
        entities.append(static_cast<Entity*>(pPlatform4));
        entities.append(static_cast<Entity*>(pPlatform5));
        entities.append(static_cast<Entity*>(pPlatform6));

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
        entities.append(static_cast<Entity*>(pPlatform));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pPlatform));
    }

    Entities::Player* Stage::createPlayer(const float x, const float y, const bool isPlayer1) {
        using namespace Entities;
        Player* pPlayer = nullptr;
        if (isPlayer1) {
            pPlayer = new Player(Texture::Player1, Constants::P1_WIDTH, Constants::P1_HEIGHT, isPlayer1);
            player = pPlayer;
            Manager::CollisionManager::getCollisionManager()->setPlayer1(pPlayer);
        }
        else {
            pPlayer = new Player(Texture::Player2, Constants::P2_WIDTH, Constants::P2_HEIGHT, isPlayer1);
            Manager::CollisionManager::getCollisionManager()->setPlayer2(pPlayer);
        }
        pPlayer->setSpritePosition(x, y);
        entities.append(static_cast<Entity*>(pPlayer));
        player->setStage(this);
        return pPlayer;
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
        entities.clear(); //preventing entities leaking to other stages
        pCollisionManager->clearLists();
        createPlayer(0.f, Constants::FLOOR_HEIGHT - Constants::P1_HEIGHT, true);
        if (!isSinglePlayer)
            createPlayer(10.f, Constants::FLOOR_HEIGHT - Constants::P2_HEIGHT, false);
        createEnemies();
        createObstacles();
    }

    void Stage::exec() {
        drawBackground();
        checkAlive();
        checkEnd();
        updateView();
        updatePointsText();
        pCollisionManager->exec();
        entities.execEntities();
        entities.drawEntities();
        pGraphicsManager->draw(pointsText);
    }

    void Stage::updatePoints(int p){
        points += p;
    }

    int Stage::getPoints(){
        return points;
    }

    void Stage::checkAlive(){
        if (player->getLife() <= 0) {
            pStateStack->pushState(States::StateType::GameOver); 
        }
    }

    void Stage::checkEnd(){
        const sf::FloatRect p1Coords = player->getGlobalHitbox();
        if ((p1Coords.left + p1Coords.width) > Constants::MAP_WIDTH) {
            States::EndMenu* paused = new States::EndMenu(this);
            pStateStack->pushState(States::StateType::EndMenu, paused, false);
        }
    }

    void Stage::pauseGame(){
        States::PausedState* paused = new States::PausedState(this);
        pStateStack->pushState(States::StateType::Paused, paused, false); 
    }

    void Stage::keyPressed(const sf::Keyboard::Key key){
        if (key == sf::Keyboard::Escape) {
            pauseGame();
        }
    }
}