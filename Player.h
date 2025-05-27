#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

#define LARGURASAMURAI 73

class Player
{
private:
    int ground;
    bool on_ground;
    sf::FloatRect rect;
    sf::Sprite player;
    float frame,speed;
    int largura,altura;
public:
    float dx, dy;

    Player(sf::RenderWindow& window, sf::Texture &texture,int largura_sprite,int altura_sprite);
    ~Player(){}

    void update(float time);
    sf::Sprite getPlayer() { return player; }
    bool getOnGround() { return on_ground; }
};