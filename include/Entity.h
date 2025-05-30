#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
    // What every entity should have:
    // - Sprite
    // - Texture
    // - Initial position (some entities won't move, so only implement initial position in parent class)
    // - Hitbox
    // - Ability to appear on screen (draw)
protected:
    sf::RenderWindow* window;  // sf::Texture& texture, int sprite_width, int sprite_height
    sf::Sprite sprite;
    sf::Texture texture;
    sf::FloatRect hitbox;
    sf::Vector2f initialPosition;

public:
    Entity() : window(nullptr) {}
    virtual ~Entity() {}

    virtual void run() = 0;          // Changed from 'executar'
    virtual void save() = 0;         // Changed from 'salvar'

    sf::FloatRect getHitbox() { return hitbox; }
    void setWindow(sf::RenderWindow* window) { this->window = window; }
    void draw() { window->draw(sprite); }
};