#pragma once
#include <SFML/Graphics.hpp>
#include <list>

#include "Event/EventObserver.h"

namespace Event {
    class EventSubject {
        protected:
            std::list<EventObserver*> observers;
            sf::Event event;

        public:
            EventSubject();
            virtual ~EventSubject();

            sf::Event getEvent() const;
            void setEvent(sf::Event e);

            virtual void attach(EventObserver*);
            virtual void detach(EventObserver*);
            virtual void notifyKeyPressed(const sf::Keyboard::Key key);
            virtual void notifyKeyReleased(const sf::Keyboard::Key key);
            virtual void notifyTextEntered(const char character);
    };
};
