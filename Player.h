#pragma once
#include"Personagem.h"
#include <SFML/Graphics.hpp>
#include<iostream>

class Player : public Personagem
{
private:
    int ground;
    bool on_ground;
    float frame,speed;
    int largura,altura;
    float dx, dy;
public:

    Player(){}
    Player(sf::Texture &texture,int largura_sprite,int altura_sprite);
    virtual ~Player(){}

    void executar() override;
    void salvar() override;
    void move() override;

    void keyboard_att(int qual_player);
    void update(float time);
    sf::Sprite getPlayer() { return sprite; }
    bool getOnGround() { return on_ground; }
};