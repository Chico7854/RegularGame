#include "Utility/Rect.h"

Rect::Rect(sf::FloatRect rect) {
    left = rect.left;
    right = rect.left + rect.width;
    top = rect.top;
    bottom = rect.top + rect.height;
}

Rect::Rect() {}

Rect::~Rect() {}