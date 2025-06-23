#pragma once
#include "States/State.h"
#include "Managers/EventManager.h"
#include "Event/EventObserver.h"
#include "States/StateStack.h"
#include "States/Menus/MenuState.h"
#include "Utility/Font.h"
#include "Utility/Constants.h"

#include <vector>
#include <string>
#include <fstream>

struct PlayerScore {
    std::string name;
    int score;
};

namespace States {
    class Leaderboard : public State {
    private:
        sf::Sprite menuButton;
        std::vector<sf::Text*> scoreEntries;
        sf::Text titleText;

        void initializeAssets();
        void loadLeaderboard();
        void clearScoreEntries();
        void draw();

    public:
        Leaderboard();
        ~Leaderboard();

        void exec() override;
        void keyPressed(const sf::Keyboard::Key key) override;
        void textEntered(const sf::Uint32 unicode) override {} 
    };
}