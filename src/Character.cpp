#include "../include/Character.h"

Character::Character() : lives(0)
{
}

Character::Character(const int width, const int height):
    Entity(width, height), 
    lives(0)
{}

Character::~Character()
{
}
