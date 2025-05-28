#pragma once
#include"Entidade.h"
#include <SFML/Graphics.hpp>
#include<iostream>

class Player : public Entidade
{
private:
    int ground;
    bool on_ground;
    //sf::FloatRect rect;
    float frame,speed;
    int largura,altura;
    float dx, dy;
public:

    Player(){}
    Player(sf::Texture &texture,int largura_sprite,int altura_sprite);
    virtual ~Player(){}

    void keyboard_att(int qual_player);
    void update(float time);
    sf::Sprite getPlayer() { return sprite; }
    bool getOnGround() { return on_ground; }
};