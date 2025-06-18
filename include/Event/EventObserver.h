#pragma once
#include <SFML/Graphics.hpp>

namespace Event {
    class EventSubject;

    class EventObserver {
        protected:
            EventSubject* pEventSubject;
            bool isActive;

        public:
            EventObserver(EventSubject* pEventSubject = NULL);
            virtual ~EventObserver();

            void setEventSubject(EventSubject* pEventSubject);

            virtual void keyPressed(const sf::Keyboard::Key key) = 0;

            const bool getIsActive() const;
            void setIsActive(const bool asA);
    };
};