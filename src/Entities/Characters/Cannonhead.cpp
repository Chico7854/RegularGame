#include "Entities/Characters/Cannonhead.h"
#include "Utility/Constants.h"
#include "Entities/Characters/Enemy.h"


namespace Entities {

    Cannonhead::Cannonhead(const Texture::ID id,const int width,const int height):
        Enemy(id, width, height, EntityType::Cannonhead),
        direction(false),
        projectileList(nullptr),
        cont_balls(0)
    {}

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

        shoot(); 

        if(projectileList){
            projectileList->updateEntities();
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
        setProjectileList();

        if(cont_balls < 5/*change for constant or change the logic for new balls after*/){
            Projectile* new_ball = new Projectile(Texture::Ball, Constants::BALL_WIDTH, Constants::BALL_HEIGHT);
            setBallDirection(); 
            
            float startX = sprite.getGlobalBounds().left + Constants::CANNONHEAD_WIDTH / 2.f;
            float startY = sprite.getGlobalBounds().top + Constants::CANNONHEAD_WIDTH / 2.f;
            
            new_ball->setInitPosition(sprite.getGlobalBounds().left + Constants::CANNONHEAD_WIDTH / 2.f, sprite.getGlobalBounds().top + Constants::CANNONHEAD_WIDTH / 2.f);
            
            if(direction){
                new_ball->setDx(speed);
            } else {
                new_ball->setDx(-speed);
            }

            projectileList->append(new_ball);
            cont_balls++;

        }

    }

    void Cannonhead::setProjectileList(){
        if (projectileList == nullptr) {
            projectileList = new List::EntityList();
        }
        else {
            std::cerr << "Projectile list already exists.\n";
        }
    }
}