#pragma once
#include "Utility/List.h"
#include "Entities/Entity.h"

namespace List {
    class EntityList {
        private:
            List<Entities::Entity*> entities;

        public:
            EntityList();
            ~EntityList();

            void append(Entities::Entity* ent);
            void deleteFromList(Entities::Entity* ent);
            void printEntities();
            void execEntities();
            void drawEntities();

            List<Entities::Entity*>::Iterator begin();
            List<Entities::Entity*>::Iterator end();
    };
}