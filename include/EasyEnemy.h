#pragma once
#include "Enemy.h"
class EasyEnemy : public Enemy
{
private:
    float frame, speed;
    int width, height;
    float dx, dy;
public:
    EasyEnemy() {}
    EasyEnemy(sf::Texture& texture, int sprite_width, int sprite_height);
    virtual ~EasyEnemy() {}
    void setInitialPosition(sf::Vector2f pos);
    void run() override;
    void save() override;
    void move() override;
    void update(float time);
};

