#include "Entities/Characters/Cannonhead.h"

namespace Entities {

    Cannonhead::Cannonhead():
        Enemy(Texture::Cannonhead, Constants::CANNONHEAD_WIDTH, Constants::CANNONHEAD_HEIGHT, EntityType::Cannonhead),
        direction(false),
        pEntityList(nullptr),
        dtime(0.f)
    {
        setEntityList();
    }

    Cannonhead::~Cannonhead() {}

    void Cannonhead::damage(Player* player) {
        player->setLife(player->getLife() - 1);
    }

    void Cannonhead::save() {
        json data = Enemy::saveDataBuffer();
        data["direction"] = direction;
        data["dtime"] = dtime;
        buffer << data.dump(4) << ",\n";
        buffer.flush();
    }

    void Cannonhead::exec()
    {
        dy += Constants::GRAVITY;
        if (sprite.getGlobalBounds().left + dx < 0 || sprite.getGlobalBounds().left + sprite.getGlobalBounds().width + dx > Constants::MAP_WIDTH) {
            dx = -dx; // Reverse direction if hits borders
        }
        moveHitboxSprite(dx, dy);

        if (!isHurt) {
            sprite.setColor(sf::Color::White);
            dtime += 0.5f;
            if(dtime > 50.f){//Change logic after 
                shoot(); 
                dtime = 0.f; // Reset dtime after shooting
            }
        } else {
            sprite.setColor(sf::Color::Red);
        }
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
    }

    void Cannonhead::setEntityList(){
        pEntityList = List::EntityList::getEntityList();
    }

    void Cannonhead::setDtime(const float dt) {
        dtime = dt;
    }

    void Cannonhead::setDirection(const bool d) {
        direction = d;
    }

    const bool Cannonhead::getDirection() const {
        return direction;
    }

    const float Cannonhead::getDtime() const {
        return dtime;
    }
}