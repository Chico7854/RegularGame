//Font pixelify sans from: https://fonts.google.com/specimen/Pixelify+Sans

#pragma once
#include <SFML/Graphics.hpp>

namespace Font {
    enum ID {
        Pixelify = 0
    };

    struct Font {
        ID id;
        sf::Font* font;
    };

    constexpr char PIXELIFY[] = "../assets/fonts/PixelifySans-Regular.ttf";
}