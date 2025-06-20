#include "States/Menus/PausedState.h"

namespace States{
    PausedState::PausedState(Event::EventSubject* pES) : selected(Options::Continue),
        Event::EventObserver(pES),
        continueButton(),
        menuButton()
    {
        setType(StateType::Paused);
        Manager::GraphicsManager::getGraphicsManager()->resetView();
        initializeAssets();
        updateSelected();

        if (pEventManager) {
            pEventManager->attach(this);
        } else {
            std::cerr << "pEventManager is nullptr in MenuState constructor!\n";
        }
    }

    void PausedState::initializeAssets(){
        if (Manager::GraphicsManager::getGraphicsManager()) {
            auto texContinue = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::Continue);
            auto texMenu = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::Menu);
            if (texContinue) {
                continueButton.setTexture(*texContinue);
            } else {
                std::cerr << "NewGameButton texture error\n";
            }
            if (texMenu) {
                menuButton.setTexture(*texMenu);
            } else {
                std::cerr << "NewGameButton texture error\n";
            }
            
            continueButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    128.f));
            menuButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    128.f * 2));
        }
    }

    PausedState::~PausedState(){

    }

    void PausedState::exec(){
        updateSelected();
        draw();
    }

    void PausedState::keyPressed(const sf::Keyboard::Key key){
        if (key == sf::Keyboard::Up) {
            if (selected == Options::Continue) {
                selected = Options::Menu;
            } else if (selected == Options::Menu) {
                selected = Options:: Continue;
            } 
            updateSelected();
        } else if (key == sf::Keyboard::Down) {
            if (selected == Options::Continue) {
                selected = Options::Menu;
            } else if (selected == Options::Menu) {
                selected = Options::Continue;
            }
            updateSelected();
        }
    }

    void PausedState::updateSelected(){
        continueButton.setColor(sf::Color::White);
        menuButton.setColor(sf::Color::White);

        if (selected == Options::Continue) {
            continueButton.setColor(sf::Color::Yellow);
        } else if (selected == Options::Menu){
            menuButton.setColor(sf::Color::Yellow);
        }
    }

    void PausedState::draw(){
        if(Manager::GraphicsManager::getGraphicsManager()){
            Manager::GraphicsManager::getGraphicsManager()->getWindow()->setView(sf::View(sf::FloatRect(0, 0, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)));
            Manager::GraphicsManager::getGraphicsManager()->draw(continueButton);
            Manager::GraphicsManager::getGraphicsManager()->draw(menuButton);
        }
    }
}