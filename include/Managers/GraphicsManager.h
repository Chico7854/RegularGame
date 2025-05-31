#pragma once

#include <SFML/Graphics.hpp>
#include "Ent.h"

namespace Manager {
    class GraphicsManager {
        private:
            sf::RenderWindow window;
            static GraphicsManager* pSelf;
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
    };
}