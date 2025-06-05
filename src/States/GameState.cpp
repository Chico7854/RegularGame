#include "States/GameState.h"

namespace States {
    GameState::GameState(Stage::Stage* s):
        stage(s)
    {}

    GameState::~GameState() {}

    void GameState::exec() {
        stage->exec();
    }
}