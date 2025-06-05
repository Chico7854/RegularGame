#include <iostream>
#include <SFML/Graphics.hpp>
#include "Managers/GraphicsManager.h"
#include "Utility/Constants.h"

namespace Manager {
    GraphicsManager* GraphicsManager::pSelf(nullptr);

    GraphicsManager::GraphicsManager():
        window(sf::VideoMode(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT), Constants::GAME_NAME),
        camera_view(sf::Vector2f(0.f,0.f),sf::Vector2f((float)Constants::WINDOW_WIDTH,(float)Constants::WINDOW_HEIGHT)),
        vectorTextures()
    {
        vectorTextures.clear();
        windowSetup();
        loadAllTextures();
    }

    GraphicsManager::~GraphicsManager() {
        for (int i = 0; i < (int)vectorTextures.size(); i++) {
            if (vectorTextures[i]) {
                delete vectorTextures[i];
            }
        }
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
        if (id >= vectorTextures.size()) {
            vectorTextures.resize(id + 1);
        }
        vectorTextures[id] = pTexture;
    }

    void GraphicsManager::loadAllTextures() {
        loadTexture(Texture::Player1, Texture::PLAYER1);
        loadTexture(Texture::Player2, Texture::PLAYER2);
        loadTexture(Texture::Youkai, Texture::YOUKAI);
        loadTexture(Texture::Platform, Texture::PLATFORM);
        loadTexture(Texture::Spike, Texture::SPIKE);
        loadTexture(Texture::Saw, Texture::SAW);
        loadTexture(Texture::Floor, Texture::FLOOR);
    }

    sf::Texture* GraphicsManager::getTexture(Texture::ID id) {
        sf::Texture* pTexture = nullptr;
        if (!vectorTextures[id]) {
            std::cerr << "Failed to find texture resource." << std::endl;
        } 
        else {
            pTexture = vectorTextures[id];
        }
        return pTexture;
    }

    /*View*/
    void GraphicsManager::setView(const sf::View& view){
        camera_view = view;
        window.setView(camera_view);
    }

    void GraphicsManager::setViewCenter(float x){
        if(x > Constants::WINDOW_WIDTH/2) { //Ensure that camera dont go out off bounds
            camera_view.setCenter(sf::Vector2f(x,Constants::WINDOW_HEIGHT/2)); //Camera just moves on the x axis
            window.setView(camera_view);
        }
    }
}

