#pragma once
#include "List.h"
#include "Entity.h"

class EntityList {
    private:
        List<Entities::Entity*> entities;

    public:
        EntityList();
        ~EntityList();
};