#include "States/MenuState.h"

namespace States{
    MenuState::MenuState(Event::EventSubject* pES) : selected(Options::NewDay),
        Event::EventObserver(pES),
        newDayButton(),
        newNightButton(),
        exitGameButton()
    {
        setType(StateType::Menu);
        pGraphicsManager->resetView();
        if (pGraphicsManager) {
            auto texNewDay = pGraphicsManager->getTexture(Texture::NewDayButton);
            auto texNewNight = pGraphicsManager->getTexture(Texture::NewNightButton);
            auto texExitGame = pGraphicsManager->getTexture(Texture::ExitGameButton);
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
        updateSelected();

        if (pEventManager) {
            pEventManager->attach(this);
        } else {
            std::cerr << "pEventManager is nullptr in MenuState constructor!\n";
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
                Stage::DayMountainStage* newDayStage = new Stage::DayMountainStage();
                DayState* dayState = new DayState(newDayStage);
                pStateStack->pushState(States::StateType::GameDay, dayState, true);
            } else if (selected == Options::NewNight) {
                Stage::NightMountainStage* newNightStage = new Stage::NightMountainStage();
                NightState* nightState = new NightState(newNightStage);
                pStateStack->pushState(States::StateType::GameNight, nightState, true);
            } else if (selected == Options::ExitGame) {
                pGraphicsManager->closeWindow();
            }
        }
    }

    void MenuState::keyReleased(const sf::Keyboard::Key key) {

    }

    void MenuState::textEntered(const char character) {

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
        if(pGraphicsManager){
            pGraphicsManager->getWindow()->setView(sf::View(sf::FloatRect(0, 0, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)));
            pGraphicsManager->draw(newDayButton);
            pGraphicsManager->draw(newNightButton);
            pGraphicsManager->draw(exitGameButton);
        }
    }
}