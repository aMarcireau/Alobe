#include "actor.h"

/**
 * Constructor
 */
Actor::Actor():
    my_events(vector<shared_ptr<Event> >())
{
}

/**
 * Attach an event
 */
void Actor::attach(shared_ptr<Event> event)
{
    my_events.push_back(event);
}

/**
 * Detach an event
 */
void Actor::detach(Event & event)
{
    for (
        vector<shared_ptr<Event> >::iterator eventIterator = my_events.begin();
        eventIterator != my_events.end();
    ) {
        if ((*eventIterator).get() == &event) {
            my_events.erase(eventIterator);
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
        vector<shared_ptr<Event> >::iterator eventIterator = my_events.begin();
        eventIterator != my_events.end();
    ) {
        (*eventIterator)->action(*this, step);
    }
}

/**
 * Is the actor dead?
 */
bool Actor::isDead()
{
    return false;
}
