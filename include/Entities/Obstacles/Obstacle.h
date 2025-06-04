#pragma once
#include "Entities/Entity.h"
#include "Entities/Characters/Character.h"

#include "Utility/Texture.h"

namespace Entities {
    class Obstacle : public Entity
    {
    protected:
    public:
        Obstacle(Texture::ID id, int sprite_width, int sprite_height);
        Obstacle();
        virtual ~Obstacle();
        virtual void save() override {}
        virtual void update() {};
        virtual void obstruct(Entities::Character* character) = 0;
    };
}