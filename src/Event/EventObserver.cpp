/* Main Include */
#include "Event/EventObserver.h"

/* Program Defined */
#include "Event/EventSubject.h"

namespace Event {
    EventObserver::EventObserver(EventSubject* pEventSubject)
      : pEventSubject(pEventSubject)
      , isActive(true)
    {

    }

    EventObserver::~EventObserver() {
      pEventSubject->detach(this);
      pEventSubject = NULL;
    }

    void EventObserver::setEventSubject(EventSubject* pEventSubject) {
      pEventSubject = pEventSubject;
    }

    const bool EventObserver::getIsActive() const {
      return isActive;
    }

    void EventObserver::setIsActive(const bool isA) {
      isActive = isA;
    }
};