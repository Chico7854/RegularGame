#include <iostream>
#include <SFML/Graphics.hpp>
#include "Managers/GraphicsManager.h"
#include "Utility/Constants.h"

namespace Manager {
    GraphicsManager* GraphicsManager::pSelf(nullptr);

    GraphicsManager::GraphicsManager():
        window(sf::VideoMode(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT), Constants::GAME_NAME),
        camera_view(sf::Vector2f(0.f,0.f),sf::Vector2f((float)Constants::WINDOW_WIDTH,(float)Constants::WINDOW_HEIGHT)),
        listTextures()
    {
        listTextures.clear();
        windowSetup();
        loadAllTextures();
    }

    GraphicsManager::~GraphicsManager() {
        std::list<Texture::Texture>::iterator it = listTextures.begin();

        while (it != listTextures.end()) {
            Texture::Texture textureStruct = *it;
            if (textureStruct.texture) {
                delete textureStruct.texture;
            }
            it++;
        }

        listTextures.clear();
    }

    GraphicsManager* GraphicsManager::getGraphicsManager() {
        if (pSelf == nullptr) {
            pSelf = new GraphicsManager;
        }
        return pSelf;
    }

    void GraphicsManager::windowSetup() {
        window.setFramerateLimit(60);
        window.setVerticalSyncEnabled(true);
        window.setMouseCursorVisible(false);
    }

    sf::RenderWindow* GraphicsManager::getWindow() {
        if (!pSelf) {
            std::cerr << "Error in getWindow" << std::endl;
        }
        return &window;
    }

    const bool GraphicsManager::isWindowOpen() const {
        return window.isOpen();
    }

    void GraphicsManager::clearWindow() {
        window.clear();
    }

    void GraphicsManager::displayWindow() {
        window.display();
    }

    void GraphicsManager::closeWindow() {
        window.close();
    }

    void GraphicsManager::drawEnt(Ent* ent) {
        window.draw(*(ent->getSprite()));
    }

    void GraphicsManager::draw(sf::Drawable &drawable) {
        window.draw(drawable);
    }

    /*Textures*/
    void GraphicsManager::loadTexture(Texture::ID id, std::string path) {
        sf::Texture* pTexture = new sf::Texture();
        if (!pTexture) {
            std::cerr << "Allocation failed" << std:: endl;
            return;
        }
        if (!(pTexture->loadFromFile(path))) {
            std::cerr << "Failed to load image." << std::endl;
            return;
        }

        Texture::Texture textureStruct = {id, pTexture};

        listTextures.push_back(textureStruct);
    }

    void GraphicsManager::loadAllTextures() {
        using namespace Texture;
        loadTexture(Player1, PLAYER1);
        loadTexture(Player2, PLAYER2);
        loadTexture(Youkai, YOUKAI);
        loadTexture(Platform, PLATFORM);
        loadTexture(Spike, SPIKE);
        loadTexture(Saw, SAW);
        loadTexture(Floor, FLOOR);
        loadTexture(BackgroundDayMountain, BACKGROUND_DAY_MOUNTAIN);
        loadTexture(BackgroundNightMountain, BACKGROUND_NIGHT_MOUNTAIN);
        loadTexture(Ball, BALL);
        loadTexture(Cannonhead, CANNONHEAD);
    }

    sf::Texture* GraphicsManager::getTexture(Texture::ID id) {
        std::list<Texture::Texture>::iterator it = listTextures.begin();
        while (it != listTextures.end()) {
            Texture::Texture textureStruct = *it;
            if (textureStruct.id == id) {
                if (textureStruct.texture) {
                    return textureStruct.texture;
                }
            }
            it++;
        }

        std::cerr << "Failed to find texture resource." << std::endl;
        return nullptr;
    }

    /*View*/
    void GraphicsManager::setView(const sf::View& view){
        camera_view = view;
        window.setView(camera_view);
    }

    void GraphicsManager::setViewCenter(float x_player){
        if(x_player > Constants::WINDOW_WIDTH/2)  //Ensure that camera dont go out off bounds
            camera_view.setCenter(sf::Vector2f(x_player,Constants::WINDOW_HEIGHT/2)); //Camera just moves on the x axis
        else
            camera_view.setCenter(sf::Vector2f(Constants::WINDOW_WIDTH/2,Constants::WINDOW_HEIGHT/2)); 
        window.setView(camera_view);
    }

    const float GraphicsManager::getViewPositionX() const {
        return camera_view.getCenter().x - Constants::WINDOW_WIDTH/2;
    }
}

