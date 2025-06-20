#include "States/Menus/MenuState.h"

namespace States{
    MenuState::MenuState(Event::EventSubject* pES) : selected(Options::NewDay),
        Event::EventObserver(pES),
        newDayButton(),
        newNightButton(),
        exitGameButton()
    {
        setType(StateType::Menu);
        Manager::GraphicsManager::getGraphicsManager()->resetView();
        initializeAssets();
        updateSelected();

        if (pEventManager) {
            pEventManager->attach(this);
        } else {
            std::cerr << "pEventManager is nullptr in MenuState constructor!\n";
        }
    }

    void MenuState::initializeAssets(){
        if (Manager::GraphicsManager::getGraphicsManager()) {
            auto texNewDay = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::NewDayButton);
            auto texNewNight = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::NewNightButton);
            auto texExitGame = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::ExitGameButton);
            if (texNewDay) {
                newDayButton.setTexture(*texNewDay);
            } else {
                std::cerr << "NewGameButton texture error\n";
            }
            if (texNewNight) {
                newNightButton.setTexture(*texNewNight);
            } else {
                std::cerr << "NewGameButton texture error\n";
            }
            if (texExitGame) {
                exitGameButton.setTexture(*texExitGame);
            } else {
                std::cerr << "ExitGameButton texture err\n";
            }
            newDayButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    128.f));
            newNightButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    128.f * 2));
            exitGameButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    128.f * 3));
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
            if (selected == Options::NewDay) {
                selected = Options::ExitGame;
            } else if (selected == Options::NewNight) {
                selected = Options:: NewDay;
            } else if (selected == Options::ExitGame) {
                selected = Options::NewNight;
            }
            updateSelected();
        } else if (key == sf::Keyboard::Down) {
            if (selected == Options::NewDay) {
                selected = Options::NewNight;
            } else if (selected == Options::NewNight) {
                selected = Options::ExitGame;
            } else if (selected == Options::ExitGame) {
                selected = Options::NewDay;
            }
            updateSelected();
        } else if (key == sf::Keyboard::Enter) {
            if (selected == Options::NewDay) {
                States::DayMountainStage* newDayStage = new States::DayMountainStage();
                pStateStack->pushState(States::StateType::GameDay, newDayStage, true);
            } else if (selected == Options::NewNight) {
                States::NightMountainStage* newNightStage = new States::NightMountainStage();
                pStateStack->pushState(States::StateType::GameNight, newNightStage, true);
            } else if (selected == Options::ExitGame) {
                Manager::GraphicsManager::getGraphicsManager()->closeWindow();
            }
        }
    }

    void MenuState::setIsActive(bool isA){
        Event::EventObserver::setIsActive(isA);
    }

    void MenuState::updateSelected(){
        newDayButton.setColor(sf::Color::White);
        newNightButton.setColor(sf::Color::White);
        exitGameButton.setColor(sf::Color::White);

        if (selected == Options::NewDay) {
            newDayButton.setColor(sf::Color::Yellow);
        } else if (selected == Options::NewNight){
            newNightButton.setColor(sf::Color::Yellow);
        } else {
            exitGameButton.setColor(sf::Color::Yellow);
        }
    }

    void MenuState::draw(){
        if(Manager::GraphicsManager::getGraphicsManager()){
            Manager::GraphicsManager::getGraphicsManager()->getWindow()->setView(sf::View(sf::FloatRect(0, 0, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)));
            Manager::GraphicsManager::getGraphicsManager()->draw(newDayButton);
            Manager::GraphicsManager::getGraphicsManager()->draw(newNightButton);
            Manager::GraphicsManager::getGraphicsManager()->draw(exitGameButton);
        }
    }
}