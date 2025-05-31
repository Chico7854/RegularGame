#include "Ent.h"
#include "Managers/GraphicsManager.h"
#include <iostream>

int Ent::cont(0);
Manager::GraphicsManager* Ent::pGraphicsManager(nullptr);

Ent::Ent():
    id(0),
    width(-1),
    height(-1),
    sprite()
{
    std::cerr << "No Parameters in Ent Constructor" << std::endl;
}

Ent::Ent(const int width, const int height):
    id(cont++),
    width(width),
    height(height),
    sprite()
{
    pGraphicsManager = Manager::GraphicsManager::getGraphicsManager();  //it has to be here because there goes a compiler error if you initialize in the static
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));
}

Ent::~Ent() {}

const int Ent::getId() const {
    return id;
}

const sf::Sprite* Ent::getSprite() {
    return &sprite;
}

// void Ent::setTexture(sf::Texture texture) {
//     sprite.setTexture(texture);
// }

void Ent::draw() {
    pGraphicsManager->drawEnt(this);
}