#include "States/StateFactory.h"

namespace States {
    StateFactory::StateFactory() {}

    StateFactory::~StateFactory() {}

    State* StateFactory::createState(States::StateType id) {
        switch (id) {
            case (States::StateType::GameDay):
                return createGameDayState();
            case (States::StateType::GameNight):
                return createGameNightState();
            default:
                std::cerr << "ERROR Failed to create State because there is no state with matching ID\n";
                exit(1);
        }
    }

    State* StateFactory::createGameDayState() {
        Stage::Stage* stage = static_cast<Stage::Stage*>(new Stage::DayMountainStage());
        if (stage == nullptr) {
            std::cerr << "ERROR when creating stage\n";
            exit(1);
        }
        stage->createMap();
        GameState* gameState = new GameState(stage);
        if (gameState == nullptr) {
            std::cerr << "ERROR when creating gameState\n";
            exit(1);
        }
        return static_cast<State*>(gameState);
    }

    State* StateFactory::createGameNightState() {
        Stage::Stage* stage = static_cast<Stage::Stage*>(new Stage::NightMountainStage());
        if (stage == nullptr) {
            std::cerr << "ERROR when creating stage\n";
            exit(1);
        }
        stage->createMap();
        GameState* gameState = new GameState(stage);
        if (gameState == nullptr) {
            std::cerr << "ERROR when creating gameState\n";
            exit(1);
        }
        return static_cast<State*>(gameState);
    }
}