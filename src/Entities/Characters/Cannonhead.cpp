#include "Entities/Characters/Cannonhead.h"
#include "Utility/Constants.h"
#include "Entities/Characters/Enemy.h"
#include "Managers/CollisionManager.h"

namespace Entities {

    Cannonhead::Cannonhead():
        Enemy(Texture::Cannonhead, Constants::CANNONHEAD_WIDTH, Constants::CANNONHEAD_HEIGHT, EntityType::Cannonhead),
        direction(false),
        projectileList(nullptr),
        cont_balls(0),
        dtime(0.f)
    {
        setProjectileList();
    }

    Cannonhead::~Cannonhead() {}

    void Cannonhead::run(){

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
        if(cont_balls<=3 && dtime > 50.f){//Change logic after 
            shoot(); 
            dtime = 0.f; // Reset dtime after shooting
        }

        if(projectileList){
            projectileList->execEntities();
            projectileList->drawEntities();
        }

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
        setBallDirection(); 
        
        float startX = sprite.getGlobalBounds().left ;//+ Constants::CANNONHEAD_WIDTH / 2.f;
        float startY = sprite.getGlobalBounds().top ;//+ Constants::CANNONHEAD_WIDTH / 2.f;
        
        new_ball->setInitPosition(startX, startY);
        
        if(direction){
            new_ball->setDx(speed);
        } else {
            new_ball->setDx(-speed);
        }

        Manager::CollisionManager::getCollisionManager()->appendProjectile(new_ball);
        projectileList->append(new_ball);
        cont_balls++;
    }

    void Cannonhead::setProjectileList(){
        projectileList = new List::EntityList();
    }

}