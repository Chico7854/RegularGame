#pragma once

#include "Obstacle.h"
#include "Utility/Texture.h"

namespace Entities {
    class Platform : public Obstacle
    {
    public:
        Platform() {}
        Platform(Texture::ID id, int sprite_width, int sprite_height): Obstacle(id, sprite_width, sprite_height)
        {
        }
        virtual ~Platform() {}

        void run() override {}
        void save() override {}
    };
}