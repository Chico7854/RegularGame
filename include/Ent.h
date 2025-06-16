#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "Utility/Texture.h"

namespace Manager{ class GraphicsManager; }

class Ent {
    protected:
        const int id;
        static int cont;
        sf::Sprite sprite;

        static Manager::GraphicsManager* pGraphicsManager;
        
    public:
        Ent();
        Ent(const Texture::ID idTexture, const int width, const int height);
        virtual ~Ent();

        const int getId() const;
        const sf::Sprite* getSprite();
        void setTexture(Texture::ID id);

        void draw();

        static void setGraphicsManager(Manager::GraphicsManager* pGM);
};