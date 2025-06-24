#include "States/Menus/GameOver.h"
#include <iostream>

namespace States {
    GameOver::GameOver() : State(Manager::EventManager::getEventManager()),
        menuButton(),
        gameOverText()
    {
        setType(StateType::GameOver);
        Manager::GraphicsManager::getGraphicsManager()->resetView();
        initializeAssets();
    }

    void GameOver::initializeAssets(){
        if (Manager::GraphicsManager::getGraphicsManager()) {
            auto texMenu = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::Menu);
            if (texMenu) {
                menuButton.setTexture(*texMenu);
                menuButton.setColor(sf::Color::Yellow);
                menuButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH / 2.f - Constants::BUTTON_WIDTH / 2.f,
                                                    Constants::WINDOW_HEIGHT / 2.f + 100.f));
            } else {
                std::cerr << "Menu button texture error\n";
            }
        }

        sf::Font* font = Manager::GraphicsManager::getGraphicsManager()->getFont(Font::Pixelify);
        if (font) {
            gameOverText.setFont(*font);
            gameOverText.setCharacterSize(48);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setString("GAME OVER");
            gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2.f, gameOverText.getLocalBounds().height / 2.f);
            gameOverText.setPosition(Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f - 50.f);
        } else {
            std::cerr << "Failed to load game font for Game Over text.\n";
        }
    }

    GameOver::~GameOver(){

    }

    void GameOver::exec(){
        draw();
    }

    void GameOver::keyPressed(const sf::Keyboard::Key key){
        if (key == sf::Keyboard::Enter) {
            pStateStack->pushState(States::StateType::Menu);
        }
    }

    void GameOver::draw(){
        if(Manager::GraphicsManager::getGraphicsManager()){
            Manager::GraphicsManager::getGraphicsManager()->getWindow()->setView(sf::View(sf::FloatRect(0, 0, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)));
            Manager::GraphicsManager::getGraphicsManager()->draw(gameOverText);
            Manager::GraphicsManager::getGraphicsManager()->draw(menuButton);
        }
    }
}