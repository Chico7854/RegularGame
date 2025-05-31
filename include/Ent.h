#pragma once

#include <SFML/Graphics.hpp>

namespace Manager{ class GraphicsManager; }

class Ent {
    protected:
        const int id;
        static int cont;
        const int width;
        const int height;
        sf::Sprite sprite;

        static Manager::GraphicsManager* pGraphicsManager;
        
    public:
        Ent();
        Ent(const int width, const int height);
        virtual ~Ent();

        const int getId() const;
        const sf::Sprite* getSprite();
        // void setTexture(sf::Texture texture);
};