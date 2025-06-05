#include "States/StateFactory.h"

namespace States {
    StateFactory::StateFactory() {}

    StateFactory::~StateFactory() {}

    State* StateFactory::createState(States::StateType id) {
        switch (id) {
            case (States::StateType::Game):
                return createGameState();
        }
    }

    State* StateFactory::createGameState() {
        Stage::Stage* stage = new Stage::Stage();
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