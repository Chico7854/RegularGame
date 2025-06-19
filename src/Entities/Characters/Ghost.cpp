#include "Entities/Characters/Ghost.h"

namespace Entities {
    Ghost::Ghost():
        Enemy(Texture::Ghost, Constants::GHOST_WIDTH, Constants::GHOST_HEIGHT, EntityType::Ghost),
        bloodDamage(1),
        direction(false),
        dtime(0.f)
    {}

    Ghost::~Ghost() {}

    const int Ghost::getBloodDamage() const {
        return bloodDamage;
    }

    void Ghost::setPlayer(Player* p){
        p1 = p;
    }

    void Ghost::setDirection(){
        sf::Vector2f playerPos = p1->getPosition();

        if(sprite.getPosition().x > playerPos.x){
            if(dx>0){
                dx *= -1;
            }
        }
        else {
            if(dx<0){
                dx *= -1;
            }
        }
    }

    void Ghost::jump(){
        dy += Constants::JUMP_SPEED;
    }

    void Ghost::damage(Player* player) {
        const sf::FloatRect charCoordinates = player->getGlobalHitbox();
        const sf::FloatRect obstacleCoordinates = getGlobalHitbox();


        if (charCoordinates.intersects(obstacleCoordinates)) {
            const float middlePointPlayer = charCoordinates.left + (charCoordinates.width / 2);
            const float middlePointEntity = obstacleCoordinates.left + (obstacleCoordinates.width / 2);

            const float playerDy = Constants::JUMP_SPEED / 1.5;
            float playerDx = Constants::SPEED * 2;

            if (middlePointPlayer < middlePointEntity) {
                playerDx *= -1;
            }

            player->setDy(playerDy);
            player->setDx(playerDx);
            player->setIsHurt(true);
            player->moveHitboxSprite(playerDx, playerDy);

            dx *= -1;
        }
    }

    void Ghost::exec(){
        /*GAMBIARRA*/
        dy += Constants::GRAVITY;
        //if (sprite.getGlobalBounds().left + dx < 0 || sprite.getGlobalBounds().left + sprite.getGlobalBounds().width + dx > Constants::WINDOW_WIDTH) {
        //    dx = -dx; // Reverse direction if hits borders
        //}
        dtime += 0.5f;
        if(dtime > 50.f){//Change logic after 
            jump(); 
            dtime = 0.f; // Reset dtime after shooting
        }
        setDirection();
        moveHitboxSprite(dx, dy);
    }
}