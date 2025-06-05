#pragma once
#include "Characters/Character.h"

namespace Entities {
    class Obstructable {
        public:
            Obstructable() {};
            ~Obstructable() {};
            virtual void obstruct(Character* character) = 0;
    };
}