/* Main Include */
#include "Utility/HitboxSprite.h"

HitboxSprite::HitboxSprite()
  : Sprite()
  , hitbox()
{

};

HitboxSprite::~HitboxSprite() {

}

sf::FloatRect HitboxSprite::getGlobalHitbox() const {
  return getTransform().transformRect(hitbox);
}

void HitboxSprite::setHitbox(const sf::FloatRect& hb) {
  hitbox = hb;
}

void HitboxSprite::updateHitbox() {
  setHitbox(getGlobalBounds());
}