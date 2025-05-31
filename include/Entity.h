#pragma once

#include <SFML/Graphics.hpp>
#include "Ent.h"

class Entity : public Ent
{
protected:
    sf::RenderWindow* window;  
    sf::FloatRect hitbox;
    sf::Vector2f initialPosition;
    int ground;

public:
    Entity() {}
    Entity(const int width, const int height): Ent(width, height), window(nullptr),ground(600/*floor height, declared statcally, chenge after*/) {}
    virtual ~Entity() {}

    virtual void run() = 0;          
    virtual void save() = 0;         

    sf::FloatRect getHitbox() { return hitbox; }
    void setWindow(sf::RenderWindow* window) { this->window = window; }
    void draw() { window->draw(sprite); }
};