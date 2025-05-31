#include <iostream>
#include <SFML/Graphics.hpp>
#include "Managers/GraphicsManager.h"
#include "Utility/Constants.h"

namespace Manager {
    GraphicsManager* GraphicsManager::pSelf(nullptr);

    GraphicsManager::GraphicsManager():
        window(sf::VideoMode(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT), Constants::GAME_NAME)
    {}

    GraphicsManager::~GraphicsManager() {}

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
}