#pragma once
#include "Entities/Entity.h"
#include "Entities/Characters/Character.h"

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
        virtual void save() override {}
        virtual void update() {};
        virtual void obstruct(Entities::Character* character) = 0;

        void setHarmful(bool harmful) { this->harmful = harmful; }
        bool isHarmful() const { return harmful; }
    };
}