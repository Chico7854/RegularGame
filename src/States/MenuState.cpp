#include "States/MenuState.h"

namespace States{
    MenuState::MenuState(Event::EventSubject* pES) : selected(Options::NewGame),
        Event::EventObserver(pES),
        newGameButton(),
        exitGameButton()
    {
        newGameButton.setTexture(*pGraphicsManager->getTexture(Texture::NewGameButton));
        newGameButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2 + Constants::BUTTON_WIDTH,128.f/*random value*/));

        exitGameButton.setTexture(*pGraphicsManager->getTexture(Texture::ExitGameButton));
        exitGameButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2 + Constants::BUTTON_WIDTH,128.f * 2/*random value*/));
        
        updateSelected();
    }

    MenuState::~MenuState(){

    }

    void MenuState::exec() {
        std::cout << "cu cu cu exec menu";
        updateSelected();
        draw();
    }

    void MenuState::keyPressed(const sf::Keyboard::Key key) {
        if (key == sf::Keyboard::Up) {
            selected = Options::NewGame;
        } else if (key == sf::Keyboard::Down) {
            selected = Options::ExitGame;
        } else if (key == sf::Keyboard::Enter) {
            if (selected == Options::NewGame) {
                Stage::DayMountainStage* newStage = new Stage::DayMountainStage();
                GameState* gameState = new GameState(newStage);
                pStateStack->pushState(States::StateType::GameDay, gameState);
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
        std::cout << "cu";
        pGraphicsManager->draw(newGameButton);
        pGraphicsManager->draw(exitGameButton);
    }
}