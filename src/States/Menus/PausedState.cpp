#include "States/Menus/PausedState.h"
#include "States/Stages/Stage.h"

namespace States{
    PausedState::PausedState(Stage* stage) : State(Manager::EventManager::getEventManager()),
        pStage(stage),
        selected(PausedOptions::Continue),
        continueButton(),
        menuButton(),
        saveGameButton()
    {
        setType(StateType::Paused);
        Manager::GraphicsManager::getGraphicsManager()->resetView();
        initializeAssets();
        updateSelected();
    }

    void PausedState::initializeAssets(){
        if (Manager::GraphicsManager::getGraphicsManager()) {
            auto texContinue = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::Continue);
            auto texMenu = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::Menu);
            auto texSave = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::Save);
            if (texContinue) {
                continueButton.setTexture(*texContinue);
            } else {
                std::cerr << "Continue texture error\n";
            }
            if (texMenu) {
                menuButton.setTexture(*texMenu);
            } else {
                std::cerr << "Menu texture error\n";
            }
            if (texSave) {
                saveGameButton.setTexture(*texSave);
            } else {
                std::cerr << "Save texture error\n";
            }
            
            continueButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    128.f));
            menuButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    128.f * 2));
            saveGameButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    128.f * 3));
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
            if (selected == PausedOptions::Continue) {
                selected = PausedOptions::SaveGame;
            } else if (selected == PausedOptions::Menu) {
                selected = PausedOptions:: Continue;
            } else if (selected == PausedOptions::SaveGame) {
                selected = PausedOptions::Menu;
            }
            updateSelected();
        } else if (key == sf::Keyboard::Down) {
            if (selected == PausedOptions::Continue) {
                selected = PausedOptions::Menu;
            } else if (selected == PausedOptions::Menu) {
                selected = PausedOptions::SaveGame;
            } else if (selected == PausedOptions::SaveGame) {
                selected = PausedOptions::Continue;
            }
            updateSelected();
        } else if (key == sf::Keyboard::Enter) {
            if (selected == PausedOptions::Continue) {
                pStateStack->popState();
            } else if (selected == PausedOptions::Menu) {
                pStateStack->pushState(States::StateType::Menu);
            } else if (selected == PausedOptions::SaveGame) {
                pStage->save();
            }
        } 
    }

    void PausedState::updateSelected(){
        continueButton.setColor(sf::Color::White);
        menuButton.setColor(sf::Color::White);
        saveGameButton.setColor(sf::Color::White);

        if (selected == PausedOptions::Continue) {
            continueButton.setColor(sf::Color::Yellow);
        } else if (selected == PausedOptions::Menu){
            menuButton.setColor(sf::Color::Yellow);
        } else if (selected == PausedOptions::SaveGame) {
            saveGameButton.setColor(sf::Color::Yellow);
        }
    }

    void PausedState::draw(){
        if(Manager::GraphicsManager::getGraphicsManager()){
            Manager::GraphicsManager::getGraphicsManager()->getWindow()->setView(sf::View(sf::FloatRect(0, 0, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)));
            Manager::GraphicsManager::getGraphicsManager()->draw(continueButton);
            Manager::GraphicsManager::getGraphicsManager()->draw(menuButton);
            Manager::GraphicsManager::getGraphicsManager()->draw(saveGameButton);
        }
    }
}