#pragma once
#include "Enemy.h"
class EasyEnemy : public Enemy
{
private:

public:
    EasyEnemy() {}
    EasyEnemy(sf::Texture& texture, int width, int height);
    virtual ~EasyEnemy() {}
    void setInitialPosition(sf::Vector2f pos);
    void run() override;
    void save() override;
    void move() override;
    void update(float time);
};

