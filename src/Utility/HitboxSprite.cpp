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

const float HitboxSprite::getGlobalBottom() const {
  return hitbox.top + hitbox.height;
}

const float HitboxSprite::getGlobalRight() const {
  return hitbox.left + hitbox.width;
}