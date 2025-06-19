#include "States/Stages/NightMountainStage.h"

namespace States {
    NightMountainStage::NightMountainStage():
        Stage(Texture::ID::BackgroundNightMountain, "../assets/stages/NightMountainMap.txt", Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)
    {
        numberOfGhosts = rand() % (maxEnemies - 3);
        numberOfGhosts += 3;
        createMap();
    }

    NightMountainStage::~NightMountainStage() {}

    void NightMountainStage::createGhost(const float x, const float y) {
        using namespace Entities;
        Ghost* pGhost = new Ghost();
        pGhost->setSpritePosition(x, y);
        pEntityList->append(static_cast<Entity*>(pGhost));
        pCollisionManager->appendEnemy(static_cast<Enemy*>(pGhost));
        pGhost->setPlayer(player);
    }

    void NightMountainStage::createSaw(const float x, const float y) {
        using namespace Entities;
        Saw* pSaw = new Saw();
        pSaw->setSpritePosition(x, y);
        pEntityList->append(static_cast<Entity*>(pSaw));
        pCollisionManager->appendObstacle(static_cast<Obstacle*>(pSaw));

    }

    void NightMountainStage::createEnemies() {
        int youkaiCount = 0;
        int ghostCount = 0;
        std::ifstream file;
        std::string line;
        file.open(mapPath);
        if (!file.is_open()) {
            std::cerr << "Couldnt open stage file\n";
            exit(1);
        }
        int j = 0;
        while(std::getline(file, line)){
            for(int i = 0; i < line.size(); i++){
                if(line[i] == 'y') {
                    if (youkaiCount < numberOfYoukais) {
                        createYoukai(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                        youkaiCount++;
                    }
                }
                else if (line[i] == 'g') {
                    if (ghostCount < numberOfGhosts) {
                        createGhost(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                        ghostCount++;
                    }
                }
            }
            j++;
        }
        file.close();
    }

    void NightMountainStage::createObstacles() {
        std::ifstream file;
        std::string line;
        file.open(mapPath);
        if (!file.is_open()) {
            std::cerr << "Couldnt open stage file\n";
            exit(1);
        }
        int j = 0;
        while(std::getline(file, line)){
            for(int i = 0; i < line.size(); i++){
                if (line[i] == '#') {
                    createBlock(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                }
                else if (line[i] == '&') {
                    createPlatform(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                }
                else if (line[i] == 'S') {
                    createSaw(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                }
            }
            j++;
        }
        file.close();
    }
}