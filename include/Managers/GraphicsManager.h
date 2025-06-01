#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Ent.h"
#include "Utility/Texture.h"

namespace Manager {
    class GraphicsManager {
        private:
            static GraphicsManager* pSelf;
            sf::RenderWindow window;
            std::vector<sf::Texture*> vectorTextures;
            GraphicsManager();

        public:
            ~GraphicsManager();
            static GraphicsManager* getGraphicsManager();

            sf::RenderWindow* getWindow();
            const bool isWindowOpen() const;
            void clearWindow();
            void displayWindow();
            void closeWindow();
            void drawEnt(Ent* ent);
            void draw(sf::Drawable &drawable);

            /*Textures*/
            void loadTexture(Texture::ID id, std::string path);
            void loadAllTextures();
            sf::Texture* getTexture(Texture::ID id);
    };
}