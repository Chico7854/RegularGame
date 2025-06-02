#pragma once

#include "Enemy.h"
#include "Utility/Texture.h"

class EasyEnemy : public Enemy
{
private:

public:
    EasyEnemy() {}
    EasyEnemy(Texture::ID id, int width, int height);
    virtual ~EasyEnemy() {}
    void setInitialPosition(sf::Vector2f pos);
    void run() override;
    void save() override;
    void move() override;
    void update(float time);
};

