#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Utility/Texture.h"

namespace Entities {
    class Cannonhead : public Enemy {
    private:
       
    public:     
        Cannonhead(Texture::ID id, int width, int height);
        Cannonhead(){}
        virtual ~Cannonhead();

        void run() override;
        void save() override;
        void update() override;
    };
}

