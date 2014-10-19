#include "actor.h"

/**
 * Constructor
 */
Actor::Actor():
    events(vector<shared_ptr<Event> >())
{
}

/**
 * Attach an event
 */
void Actor::attach(shared_ptr<Event> event)
{
    events.push_back(event);
}

/**
 * Detach an event
 */
void Actor::detach(Event & event)
{
    for (
        vector<shared_ptr<Event> >::iterator eventIterator = events.begin();
        eventIterator != events.end();
    ) {
        if ((*eventIterator).get() == &event) {
            events.erase(eventIterator);
        } else {
            ++eventIterator;
        }
    }
}

/**
 * Notification called by a Stepper object
 */
void Actor::notify(unsigned int step)
{
    for (
        vector<shared_ptr<Event> >::iterator eventIterator = events.begin();
        eventIterator != events.end();
    ) {
        (*eventIterator)->action(*this, step);
    }
}
