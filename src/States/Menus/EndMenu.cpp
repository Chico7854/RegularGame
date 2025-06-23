#include "States/Menus/EndMenu.h"
#include "States/Stages/Stage.h"

namespace States{
    EndMenu::EndMenu(Stage* stage) : State(Manager::EventManager::getEventManager()),
        pStage(stage),
        selected(EndOptions::SaveScore),
        saveScoreButton(),
        menuButton(),
        points(0),
        playerName(""),
        nameInputActive(true)
    {
        setType(StateType::EndMenu);
        Manager::GraphicsManager::getGraphicsManager()->resetView();
        points = pStage->getPoints();
        initializeAssets();
        updateSelected();
    }

    void EndMenu::initializeAssets(){
        if (Manager::GraphicsManager::getGraphicsManager()) {
            auto texSaveScore = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::SaveScore);
            auto texMenu = Manager::GraphicsManager::getGraphicsManager()->getTexture(Texture::Menu);
            if (texSaveScore) {
                saveScoreButton.setTexture(*texSaveScore);
            } else {
                std::cerr << "SaveScore texture error\n";
            }
            if (texMenu) {
                menuButton.setTexture(*texMenu);
            } else {
                std::cerr << "Menu texture error\n";
            }
            
            saveScoreButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    128.f * 3));
            menuButton.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH/2.f - Constants::BUTTON_WIDTH/2.f ,
                                                    128.f * 4));
        }

        sf::Font* Font = Manager::GraphicsManager::getGraphicsManager()->getFont(Font::Pixelify);
        if (Font) {
            pointsText.setFont(*Font);
            pointsText.setCharacterSize(24);
            pointsText.setFillColor(sf::Color::White);
            pointsText.setString("Points: " + std::to_string(points));
            pointsText.setPosition(Constants::WINDOW_WIDTH/2, 
                                   Constants::WINDOW_HEIGHT/2);//adjust to the midlle after
            
            nameText.setFont(*Font);
            nameText.setCharacterSize(24);
            nameText.setFillColor(sf::Color::White);
            nameText.setString("Enter Name: ");
            nameText.setPosition(Constants::WINDOW_WIDTH/2.f - nameText.getGlobalBounds().width/2.f, 
                                 Constants::WINDOW_HEIGHT/2.f + 32.f);
        } else {
            std::cerr << "Failed to load game font.\n";
        }
    }

    EndMenu::~EndMenu(){

    }

    void EndMenu::exec(){
        if (nameInputActive){
            nameText.setString("Enter name: " + playerName + "_");
        } else{
            nameText.setString("Enter name: " + playerName);
            updateSelected();
        }
        draw();
    }

    void EndMenu::keyPressed(const sf::Keyboard::Key key){
            if (nameInputActive) {
                if (key == sf::Keyboard::Enter) {
                    if (!playerName.empty()) { 
                        nameInputActive = false;
                        selected = EndOptions::SaveScore;
                        updateSelected();
                    }
                } else if (key == sf::Keyboard::BackSpace) { 
                    if (!playerName.empty()) {
                        playerName.pop_back();
                    }
                }
            
            } else {
            if (key == sf::Keyboard::Up) {
                if (selected == EndOptions::SaveScore) {
                    selected = EndOptions::Menu;
                } else if (selected == EndOptions::Menu) {
                    selected = EndOptions::SaveScore;
                }
                updateSelected();
            } else if (key == sf::Keyboard::Down) {
                if (selected == EndOptions::SaveScore) {
                    selected = EndOptions::Menu;
                } else if (selected == EndOptions::Menu) {
                    selected = EndOptions::SaveScore;
                } 
                updateSelected();
            } else if (key == sf::Keyboard::Enter) {
                if (selected == EndOptions::SaveScore) {
                    saveOnTxt();
                } else if (selected == EndOptions::Menu) {
                    pStateStack->pushState(States::StateType::Menu);
                }
            } 
        }
    }

    void EndMenu::textEntered(const sf::Uint32 unicode){
        if (nameInputActive) {
            if (unicode >= 32 && unicode < 127) { 
                if (playerName.length() < 15) { 
                    playerName += static_cast<char>(unicode);
                }
            }
        }
    }

    void EndMenu::updateSelected(){
        saveScoreButton.setColor(sf::Color::White);
        menuButton.setColor(sf::Color::White);

        if (selected == EndOptions::SaveScore) {
            saveScoreButton.setColor(sf::Color::Yellow);
        } else if (selected == EndOptions::Menu){
            menuButton.setColor(sf::Color::Yellow);
        } 
    }

    void EndMenu::saveOnTxt(){
        std::ofstream file("../data/leaderboard.txt", std::ios::app); 
        if (file.is_open()) {
            file << playerName << " " << points << std::endl;
            file.close();
        } else {
            std::cerr << "error opening leaderboard.txt" << std::endl;
        }
    }

    void EndMenu::draw(){
        if(Manager::GraphicsManager::getGraphicsManager()){
            Manager::GraphicsManager::getGraphicsManager()->getWindow()->setView(sf::View(sf::FloatRect(0, 0, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT)));
            Manager::GraphicsManager::getGraphicsManager()->draw(saveScoreButton);
            Manager::GraphicsManager::getGraphicsManager()->draw(menuButton);
            Manager::GraphicsManager::getGraphicsManager()->draw(pointsText);
            Manager::GraphicsManager::getGraphicsManager()->draw(nameText);
        }
    }
}