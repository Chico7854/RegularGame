#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace Manager{ class GraphicsManager; }

class Ent {
    protected:
        const int id;
        static int cont;
        const int width;
        const int height;
        sf::Sprite sprite;
        sf::Texture texture;

        static Manager::GraphicsManager* pGraphicsManager;
        
    public:
        Ent();
        Ent(const int width, const int height);
        virtual ~Ent();

        const int getId() const;
        const sf::Sprite* getSprite();
        void setTexture(std::string path);
        void draw();
};