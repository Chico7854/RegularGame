#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Utility/Texture.h"
#include "Utility/HitboxSprite.h"

namespace Manager{ class GraphicsManager; }

class Ent {
    protected:
        const int id;
        static int cont;
        HitboxSprite sprite;    //I think you can use only the sprite as a hitbox, no need for the extra class but whatever

        static Manager::GraphicsManager* pGraphicsManager;
        
    public:
        Ent();
        Ent(Texture::ID idTexture, int width, const int height);
        virtual ~Ent();

        const int getId() const;
        const sf::Sprite* getSprite();
        const sf::FloatRect getGlobalHitbox() const;
        void setTexture(Texture::ID id);

        void setSpritePosition(float x, float y);

        void draw();
};