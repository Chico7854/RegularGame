#include "Entities/Characters/Cannonhead.h"
#include "Utility/Constants.h"
#include "Entities/Characters/Enemy.h"
#include "Managers/CollisionManager.h"

namespace Entities {

    Cannonhead::Cannonhead():
        Enemy(Texture::Cannonhead, Constants::CANNONHEAD_WIDTH, Constants::CANNONHEAD_HEIGHT, EntityType::Cannonhead),
        direction(false),
        pEntityList(nullptr),
        cont_balls(0),
        dtime(0.f)
    {
        setEntityList();
    }

    Cannonhead::~Cannonhead() {}

    void Cannonhead::damage(Player* player) {
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

    void Cannonhead::save(){
    }

    void Cannonhead::exec()
    {
        /*GAMBIARRA*/
        dy += Constants::GRAVITY;
        if (sprite.getGlobalBounds().left + dx < 0 || sprite.getGlobalBounds().left + sprite.getGlobalBounds().width + dx > Constants::WINDOW_WIDTH) {
            dx = -dx; // Reverse direction if hits borders
        }
        moveHitboxSprite(dx, dy);

        dtime += 0.5f;
        if(dtime > 50.f){//Change logic after 
            shoot(); 
            dtime = 0.f; // Reset dtime after shooting
        }

        /*if(pProjectileList){
            projectileList->execEntities();
            projectileList->drawEntities();
        }*/

        // frame += 0.008f * time; // Animation speed
        // if (frame >= 6) {
        //     frame = 0;
        // }

        // if (dx > 0) {
        //     sprite.setTextureRect(sf::IntRect(width * (int)frame, 0, width, height));
        // }
        // if (dx < 0) {
        //     sprite.setTextureRect(sf::IntRect(width * ((int)frame + 1), 0, -width, height));
        // }
    }

    void Cannonhead::setBallDirection(){
        if(dx > 0){
            direction = true; // Right
        } else {
            direction = false; // Left
        }
    }

    void Cannonhead::shoot(){

        Projectile* new_ball = new Projectile(Texture::Ball, Constants::BALL_WIDTH, Constants::BALL_HEIGHT);
        
        float startX = sprite.getGlobalBounds().left ;//+ Constants::CANNONHEAD_WIDTH / 2.f;
        float startY = sprite.getGlobalBounds().top ;//+ Constants::CANNONHEAD_WIDTH / 2.f;
        
        new_ball->setInitPosition(startX, startY);

        setBallDirection(); 
        new_ball->setDirection(direction);
        

        Manager::CollisionManager::getCollisionManager()->appendProjectile(new_ball);
        pEntityList->append(new_ball);
        cont_balls++;
    }

    void Cannonhead::setEntityList(){
        pEntityList = List::EntityList::getEntityList();
    }

}