#pragma once
#include"Personagem.h"
#include <SFML/Graphics.hpp>
#include<iostream>

class Inimigo : public Personagem
{
private:
    int ground;
    float frame, speed;
    int largura, altura;
    float dx, dy;
public:

    Inimigo() {}
    Inimigo(sf::Texture& texture, int largura_sprite, int altura_sprite);
    virtual ~Inimigo() {}
    void setInitPosition(sf::Vector2f pos);
    void executar() override;
    void salvar() override;
    void move() override;

    void update(float time);
    sf::Sprite getInimigo() { return sprite; }
};
