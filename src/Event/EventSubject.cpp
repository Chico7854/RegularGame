#include "Event/EventSubject.h"

/* Program Defined */
#include <algorithm>

namespace Event {
    EventSubject::EventSubject() {

    }

    EventSubject::~EventSubject() {
      std::list<EventObserver*>::iterator it = observers.begin();

      while (it != observers.end()) {
        observers.remove(*it);
        it++;
      }
    }
    
    sf::Event EventSubject::getEvent() const {
      return event;
    }

    void EventSubject::setEvent(sf::Event e) {
      event = e;
    }
    
    void EventSubject::attach(EventObserver* o) {
      // Checks if element isn't already in the list
      if (std::find(observers.begin(), observers.end(), o) == observers.end())
        observers.push_back(o);
    }

    void EventSubject::detach(EventObserver* o) {
      observers.remove(o);
    }
    
    void EventSubject::notifyKeyPressed(const sf::Keyboard::Key key) {
      std::list<EventObserver*>::iterator it = observers.begin();

      while (it != observers.end()) {
        if ((*it)->getIsActive())
          (*it)->keyPressed(key);
        it++;
      }
    }

    void EventSubject::notifyKeyReleased(const sf::Keyboard::Key key) {
      std::list<EventObserver*>::iterator it = observers.begin();

      while (it != observers.end()) {
        if ((*it)->getIsActive())
          (*it)->keyReleased(key);
        it++;
      }
    }

    void EventSubject::notifyTextEntered(const char character) {
      std::list<EventObserver*>::iterator it = observers.begin();

      while (it != observers.end()) {
        if ((*it)->getIsActive())
          (*it)->textEntered(character);
        it++;
      }
    }
};