#include "States/MenuState.h"

namespace States{
    MenuState::MenuState(Event::EventSubject* pES) : selected(Options::NewGame),
        Event::EventObserver(pES),
        newGameButton(),
        exitGameButton()
    {
        setType(StateType::Menu);
        pGraphicsManager->resetView();
        if (pGraphicsManager) {
            auto texNewGame = pGraphicsManager->getTexture(Texture::NewGameButton);
            auto texExitGame = pGraphicsManager->getTexture(Texture::ExitGameButton);
            if (texNewGame) {
                newGameButton.setTexture(*texNewGame);
            } else {
                std::cerr << "NewGameButton texture error\n";
            }
            if (texExitGame) {
                exitGameButton.setTexture(*texExitGame);
            } else {
                std::cerr << "ExitGameButton texture err\n";
            }
            newGameButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    128.f));
            exitGameButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    128.f * 2));
        }
        updateSelected();

        if (pEventManager) {
            pEventManager->attach(this);
        } else {
            std::cerr << "pEventManager is nullptr in MenuState constructor!\n";
        }
    }

    MenuState::~MenuState(){

    }

    void MenuState::exec() {
        updateSelected();
        draw();
    }

    void MenuState::keyPressed(const sf::Keyboard::Key key) {
        if (key == sf::Keyboard::Up) {
            selected = Options::NewGame;
            updateSelected();
        } else if (key == sf::Keyboard::Down) {
            selected = Options::ExitGame;
            updateSelected();
        } else if (key == sf::Keyboard::Enter) {
            if (selected == Options::NewGame) {
                Stage::DayMountainStage* newStage = new Stage::DayMountainStage();
                GameState* gameState = new GameState(newStage);
                pStateStack->pushState(States::StateType::GameDay, gameState, true);
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
        newGameButton.setColor(sf::Color::White);
        exitGameButton.setColor(sf::Color::White);

        if (selected == Options::NewGame) {
            newGameButton.setColor(sf::Color::Yellow);
        } else {
            exitGameButton.setColor(sf::Color::Yellow);
        }
    }

    void MenuState::draw(){
        if(pGraphicsManager){
            pGraphicsManager->getWindow()->setView(sf::View(sf::FloatRect(0, 0, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)));
            pGraphicsManager->draw(newGameButton);
            pGraphicsManager->draw(exitGameButton);
        }
    }
}