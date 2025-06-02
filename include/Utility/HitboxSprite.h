#pragma once
#include <SFML/Graphics.hpp>

// Código baseado no proposto por Lily
// https://stackoverflow.com/questions/64727496/c-sfml-how-can-i-create-a-collision-box-for-my-sprite
class HitboxSprite : public sf::Sprite {
  private:
    sf::FloatRect hitbox;

  public:
    HitboxSprite();
    ~HitboxSprite();
    sf::FloatRect getGlobalHitbox() const;
    void setHitbox(const sf::FloatRect& hb);
    void updateHitbox();
};