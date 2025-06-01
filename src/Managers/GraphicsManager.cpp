#include <iostream>
#include <SFML/Graphics.hpp>
#include "Managers/GraphicsManager.h"
#include "Utility/Constants.h"

namespace Manager {
    GraphicsManager* GraphicsManager::pSelf(nullptr);

    GraphicsManager::GraphicsManager():
        window(sf::VideoMode(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT), Constants::GAME_NAME),
        vectorTextures()
    {
        vectorTextures.clear();
        loadAllTextures();
    }

    GraphicsManager::~GraphicsManager() {
        for (int i = 0; i < (int)vectorTextures.size(); i++) {
            if (vectorTextures[i]) {
                delete vectorTextures[i];
            }
        }
        if (pSelf) {
            delete pSelf;
        }
    }

    GraphicsManager* GraphicsManager::getGraphicsManager() {
        if (pSelf == nullptr) {
            pSelf = new GraphicsManager;
        }
        return pSelf;
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
}