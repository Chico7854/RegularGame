#include "States/Menus/MenuState.h"
#include "States/Stages/DayMountainStage.h"
#include "States/Stages/NightMountainStage.h"

namespace States{
    bool MenuState::isSingle(true);

    MenuState::MenuState() : State(Manager::EventManager::getEventManager()),
        selected(MenuOptions::NewDay),
        newDayButton(),
        newNightButton(),
        exitGameButton(),
        loadGameButton(),
        leaderboard(),
        singleplayer(),
        multiplayer()
    {
        setType(StateType::Menu);
        Manager::GraphicsManager::getGraphicsManager()->resetView();
        initializeAssets();
        updateSelected();
    }

    void MenuState::initializeAssets(){
        if (Manager::GraphicsManager::getGraphicsManager()) {
            auto texNewDay = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::NewDayButton);
            auto texNewNight = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::NewNightButton);
            auto texExitGame = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::ExitGameButton);
            auto texLoadGame = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::Load);
            auto texLeaderboard = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::Leaderboard);
            auto texSingle = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::Single);
            auto texMulti = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::Multi);
            if (texNewDay) {
                newDayButton.setTexture(*texNewDay);
            } else {
                std::cerr << "NewDayButton texture error\n";
            }
            if (texNewNight) {
                newNightButton.setTexture(*texNewNight);
            } else {
                std::cerr << "NewNightButton texture error\n";
            }
            if (texExitGame) {
                exitGameButton.setTexture(*texExitGame);
            } else {
                std::cerr << "ExitGameButton texture err\n";
            }
            if (texLoadGame) {
                loadGameButton.setTexture(*texLoadGame);
            } else {
                std::cerr << "Load texture err\n";
            }
            if (texLeaderboard) {
                leaderboard.setTexture(*texLeaderboard);
            } else {
                std::cerr << "Leader texture err\n";
            }
            if (texSingle) {
                singleplayer.setTexture(*texSingle);
            } else {
                std::cerr << "Single texture err\n";
            }
            if (texMulti) {
                multiplayer.setTexture(*texMulti);
            } else {
                std::cerr << "Multi texture err\n";
            }
            newDayButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    96.f));
            newNightButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    96.f * 2));
            singleplayer.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    96.f * 3));
            multiplayer.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    96.f * 3));
            loadGameButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    96.f * 4));
            leaderboard.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    96.f * 5));   
            exitGameButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    96.f * 6));                                                                             
        }
    }

    MenuState::~MenuState(){
        if (pEventManager)
            pEventManager->detach(this);
    }

    void MenuState::exec() {
        updateSelected();
        draw();
    }

    void MenuState::keyPressed(const sf::Keyboard::Key key) {
        if (key == sf::Keyboard::Up) {
            if (selected == MenuOptions::NewDay) {
                selected = MenuOptions::ExitGame;
            } else if (selected == MenuOptions::NewNight) {
                selected = MenuOptions:: NewDay;
            } else if (selected == MenuOptions::GameMode) {
                selected = MenuOptions::NewNight;
            } else if (selected == MenuOptions::LoadGame) {
                selected = MenuOptions::GameMode;
            } else if (selected == MenuOptions::Leaderboard) {
                selected = MenuOptions::LoadGame;
            } else if (selected == MenuOptions::ExitGame) {
                selected = MenuOptions::Leaderboard;
            }
            updateSelected();
        } else if (key == sf::Keyboard::Down) {
            if (selected == MenuOptions::NewDay) {
                selected = MenuOptions::NewNight;
            } else if (selected == MenuOptions::NewNight) {
                selected = MenuOptions::GameMode;
            } else if (selected == MenuOptions::GameMode) {
                selected = MenuOptions::LoadGame;
            } else if (selected == MenuOptions::LoadGame) {
                selected = MenuOptions::Leaderboard;
            } else if (selected == MenuOptions::Leaderboard) {
                selected = MenuOptions::ExitGame;
            } else if (selected == MenuOptions::ExitGame) {
                selected = MenuOptions::NewDay;
            }
            updateSelected();
        } else if (key == sf::Keyboard::Enter) {
            if (selected == MenuOptions::NewDay) {
                pStateStack->pushState(States::StateType::GameDay);
            } else if (selected == MenuOptions::NewNight) {//
                pStateStack->pushState(States::StateType::GameNight);
            } else if (selected == MenuOptions::GameMode) {
                if(isSingle){ isSingle = false; }
                else { isSingle = true; }
            } else if (selected == MenuOptions::LoadGame) {
                pStateStack->pushState(States::StateType::LoadGame);
            } else if (selected == MenuOptions::Leaderboard) {
                pStateStack->pushState(States::StateType::Leaderboard);
            } else if (selected == MenuOptions::ExitGame) {
                Manager::GraphicsManager::getGraphicsManager()->closeWindow();
            } 
        }
        std::cout << "Menu:" << (int)selected << "\n";
    }

    void MenuState::setIsActive(bool isA){
        Event::EventObserver::setIsActive(isA);
    }

    const bool MenuState::getIsSingle() {
        return isSingle;
    }

    void MenuState::updateSelected(){
        newDayButton.setColor(sf::Color::White);
        newNightButton.setColor(sf::Color::White);
        exitGameButton.setColor(sf::Color::White);
        loadGameButton.setColor(sf::Color::White);
        leaderboard.setColor(sf::Color::White);
        singleplayer.setColor(sf::Color::White);
        multiplayer.setColor(sf::Color::White);

        if (selected == MenuOptions::NewDay) {
            newDayButton.setColor(sf::Color::Yellow);
        } else if (selected == MenuOptions::NewNight) {
            newNightButton.setColor(sf::Color::Yellow);
        } else if (selected == MenuOptions::ExitGame) {
            exitGameButton.setColor(sf::Color::Yellow);
        } else if (selected == MenuOptions::LoadGame) {
            loadGameButton.setColor(sf::Color::Yellow);
        } else if (selected == MenuOptions::Leaderboard) {
            leaderboard.setColor(sf::Color::Yellow);
        } else if (selected == MenuOptions::GameMode) {
            singleplayer.setColor(sf::Color::Yellow);
            multiplayer.setColor(sf::Color::Yellow);
        } 
    }

    void MenuState::draw(){
        if(Manager::GraphicsManager::getGraphicsManager()){
            Manager::GraphicsManager::getGraphicsManager()->getWindow()->setView(sf::View(sf::FloatRect(0, 0, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)));
            Manager::GraphicsManager::getGraphicsManager()->draw(newDayButton);
            Manager::GraphicsManager::getGraphicsManager()->draw(newNightButton);
            Manager::GraphicsManager::getGraphicsManager()->draw(exitGameButton);
            Manager::GraphicsManager::getGraphicsManager()->draw(loadGameButton);
            Manager::GraphicsManager::getGraphicsManager()->draw(leaderboard);
            if (isSingle) {
                Manager::GraphicsManager::getGraphicsManager()->draw(singleplayer);
            } else {
                Manager::GraphicsManager::getGraphicsManager()->draw(multiplayer);
            }
        }
    }
}