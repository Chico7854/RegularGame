#pragma once
#include "Obstacle.h"
#include "Entities/Characters/Character.h"

#include "Utility/Texture.h"

namespace Entities {
    class Platform : public Obstacle
    {
    public:
        Platform(Texture::ID id, int sprite_width, int sprite_height);
        Platform();
        virtual ~Platform();

        void obstruct(Entities::Character* character) override;
        void save() override {} 
    };
}