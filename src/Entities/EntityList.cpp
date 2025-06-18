#include "Entities/EntityList.h"

namespace List {
    EntityList* EntityList::pSelf(nullptr);

    EntityList::EntityList():
        entities()
    {}

    EntityList::~EntityList() {}

    EntityList* EntityList::getEntityList() {
        if (!pSelf) {
            pSelf = new EntityList();
        }
        return pSelf;
    }

    void EntityList::append(Entities::Entity* ent) {
        if (ent) {
            entities.pushBack(ent);
        }
        else {
            std::cerr << "Failed to append to list because entity is null.\n";
        }
    }

    void EntityList::deleteFromList(Entities::Entity* ent){
        if(ent){
            entities.remove(ent);
            delete ent;
        }
    }

    void EntityList::printEntities() {
        List<Entities::Entity*>::Iterator it = entities.getHead();

        while (it != nullptr) {
            std::cout << *it << std::endl;
            it++;
        }
    }

    void EntityList::execEntities() {
        List<Entities::Entity*>::Iterator it = entities.getHead();
        while (it != nullptr) {
            if (*it) {
                if((*it)->getToDelete()){
                    deleteFromList(*it);
                }
                else {
                    (*it)->exec();
                }
            }
            it++;
        }
    }

    void EntityList::drawEntities() {
        List<Entities::Entity*>::Iterator it = entities.getHead();
        while (it != nullptr) {
            if (*it) {
                (*it)->draw();
            }
            it++;
        }
    }

    List<Entities::Entity*>::Iterator EntityList::begin() {
        return entities.getHead();
    }

    List<Entities::Entity*>::Iterator EntityList::end() {
        return nullptr;
    }
}