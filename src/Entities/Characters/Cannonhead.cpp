#include "Entities/Characters/Cannonhead.h"
#include "Utility/Constants.h"
#include "Entities/Characters/Enemy.h"


namespace Entities {

    Cannonhead::Cannonhead(const Texture::ID id,const int width,const int height):
        Enemy(id, width, height, EntityType::Cannonhead),
        direction(false),
        projectileList(nullptr),
        cont_balls(0)
    {
        setProjectileList();
    }

    Cannonhead::~Cannonhead() {}

    void Cannonhead::run(){

    }

    void Cannonhead::save(){
    }

    void Cannonhead::update()
    {
        /*GAMBIARRA*/
        dy += Constants::GRAVITY;
        if (sprite.getGlobalBounds().left + dx < 0 || sprite.getGlobalBounds().left + sprite.getGlobalBounds().width + dx > Constants::WINDOW_WIDTH) {
            dx = -dx; // Reverse direction if hits borders
        }
        moveHitboxSprite(dx, dy);

        if(cont_balls<1)//Change logic after 
            shoot(); 

        if(projectileList){
            projectileList->updateEntities();
        }

        if(projectileList)
            projectileList->drawEntities();

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
            
            float startX = sprite.getGlobalBounds().left + Constants::CANNONHEAD_WIDTH / 2.f;
            float startY = sprite.getGlobalBounds().top + Constants::CANNONHEAD_WIDTH / 2.f;
            
            new_ball->setInitPosition(startX, startY);
            
            if(direction){
                new_ball->setDx(speed);
            } else {
                new_ball->setDx(-speed);
            }

            projectileList->append(new_ball);
            cont_balls++;
    }

    void Cannonhead::setProjectileList(){
        if (projectileList == nullptr) {
            projectileList = new List::EntityList();
        }
    }
}