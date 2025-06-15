#include "Stage/DayMountainStage.h"

namespace Stage {
    DayMountainStage::DayMountainStage():
        Stage(Texture::ID::BackgroundDayMountain, "../assets/stages/DayMountainMap.txt", Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)
    {
        createMap();
    }

    DayMountainStage::~DayMountainStage() {}

    void DayMountainStage::createEnemies() {
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
                    createYoukai(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                }
            }
            j++;
        }
        file.close();
    }

    void DayMountainStage::createObstacles() {
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
                if(line[i] == '#') {
                    createPlatform(i * Constants::SCALE_TXT, j * Constants::SCALE_TXT);
                }
            }
            j++;
        }
        file.close();
    }
}