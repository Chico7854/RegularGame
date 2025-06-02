#pragma once

#include "../Entity.h"
#include "Utility/Texture.h"

namespace Entities {
    class Obstacle : public Entity
    {
    protected:
        bool harmful;
    public:
        Obstacle() : harmful(false) {}
        Obstacle(Texture::ID id, int sprite_width, int sprite_height): Entity(id, sprite_width, sprite_height)
        {
        }
        virtual ~Obstacle() {}
        virtual void run() override {}
        virtual void save() override {}
        virtual void update() {};
        void setHarmful(bool harmful) { this->harmful = harmful; }
        bool isHarmful() const { return harmful; }
    };
}