#include "Entities/Characters/Boss.h"

namespace Entities {
    Boss::Boss():
        bloodDamage(1)
    {}

    Boss::~Boss() {}

    const int Boss::getBloodDamage() const {
        return bloodDamage;
    }
}