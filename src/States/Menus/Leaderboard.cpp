#include "States/Menus/Leaderboard.h"

namespace States {
    Leaderboard::Leaderboard() : State(Manager::EventManager::getEventManager()),
        menuButton()
    {
        setType(StateType::Leaderboard);
        Manager::GraphicsManager::getGraphicsManager()->resetView();
        initializeAssets();
        loadLeaderboard();
    }

    Leaderboard::~Leaderboard() {
        clearScoreEntries();
    }

    void Leaderboard::initializeAssets() {
        if (Manager::GraphicsManager::getGraphicsManager()) {
            auto texBack = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::Menu); 
            if (texBack) {
                menuButton.setTexture(*texBack);
                menuButton.setColor(sf::Color::Yellow);
                menuButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH / 2.f - Constants::BUTTON_WIDTH / 2.f,
                                                    Constants::WINDOW_HEIGHT - 128.f));
            } else {
                std::cerr << "MEnu button texture error\n";
            }
        }

        sf::Font* font = Manager::GraphicsManager::getGraphicsManager()->getFont(Font::Pixelify);
        if (font) {
            titleText.setFont(*font);
            titleText.setCharacterSize(48);
            titleText.setFillColor(sf::Color::Yellow);
            titleText.setString("LEADERBOARD");
            titleText.setOrigin(titleText.getLocalBounds().width / 2.f, titleText.getLocalBounds().height / 2.f);
            titleText.setPosition(Constants::WINDOW_WIDTH / 2.f, 50.f);
        } else {
            std::cerr << "Failed to load game font for leaderboard title.\n";
        }
    }

    void Leaderboard::loadLeaderboard() {
        clearScoreEntries(); 

        std::ifstream file("../data/leaderboard.txt");
        if (!file.is_open()) {
            std::cerr << "Error opening leaderboard.txt\n";
            return;
        }

        std::vector<PlayerScore> scores;
        std::string line;
        while (std::getline(file, line)) {
            size_t spacePos = line.find(' ');
            if (spacePos != std::string::npos) {
                PlayerScore ps;
                ps.name = line.substr(0, spacePos); //put the struct, substr receives the start position and the length
                ps.score = std::stoi(line.substr(spacePos + 1)); //converto to int and put whats after the space in the struct
                scores.push_back(ps);
            }
        }

        file.close();

        for (size_t i = 0; i < scores.size(); ++i) { //Selection sort
            size_t maxIdx = i;
            for (size_t j = i + 1; j < scores.size(); ++j) {
                if (scores[j].score > scores[maxIdx].score) {
                    maxIdx = j;
                }
            }
            if (maxIdx != i) {
                std::swap(scores[i], scores[maxIdx]);
            }
        }

        float ySpace = 150.f;
        sf::Font* font = Manager::GraphicsManager::getGraphicsManager()->getFont(Font::Pixelify);
        if (!font) {
            std::cerr << "Font not loaded for score entries.\n";
            return;
        }

        for (size_t i = 0; i < scores.size() && i < 10; ++i) {
            sf::Text* entryText = new sf::Text();
            entryText->setFont(*font);
            entryText->setCharacterSize(24);
            entryText->setFillColor(sf::Color::White);
            std::string scoreString = std::to_string(i + 1) + ". " + scores[i].name + " - " + std::to_string(scores[i].score);
            entryText->setString(scoreString);
            entryText->setOrigin(entryText->getLocalBounds().width / 2.f, entryText->getLocalBounds().height / 2.f);
            entryText->setPosition(Constants::WINDOW_WIDTH / 2.f, ySpace);
            scoreEntries.push_back(entryText);
            ySpace += 40.f;
        }
    }

    void Leaderboard::clearScoreEntries() {
        for (sf::Text* text : scoreEntries) {
            delete text;
        }
        scoreEntries.clear();
    }

    void Leaderboard::exec() {
        draw();
    }

    void Leaderboard::keyPressed(const sf::Keyboard::Key key) {
        if (key == sf::Keyboard::Escape || key == sf::Keyboard::Enter) {
            pStateStack->popState(); 
        }
    }

    void Leaderboard::draw() {
        if (Manager::GraphicsManager::getGraphicsManager()) {
            Manager::GraphicsManager::getGraphicsManager()->getWindow()->setView(sf::View(sf::FloatRect(0, 0, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)));
            Manager::GraphicsManager::getGraphicsManager()->draw(titleText);
            for (size_t i = 0; i < scoreEntries.size(); ++i) {
                Manager::GraphicsManager::getGraphicsManager()->draw(*scoreEntries[i]);
            }
            Manager::GraphicsManager::getGraphicsManager()->draw(menuButton);
        }
    }
}