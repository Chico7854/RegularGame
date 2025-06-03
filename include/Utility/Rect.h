#pragma once
#include <SFML/Graphics.hpp>

class Rect {
    public:
        float left, right, top, bottom;   //top left, top right, bottom left, bottom right

        Rect(sf::FloatRect rect);
        Rect();
        ~Rect();
};