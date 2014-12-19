#include "actor.h"

/**
 * Constructor
 */
Actor::Actor(unique_ptr<Graphics> graphics):
    my_graphics(move(graphics)),
    my_events(vector<shared_ptr<Event> >())
{
}

/**
 * Getter for the Graphics
 */
Graphics * Actor::getGraphics()
{
    return my_graphics.get();
}

/**
 * Attach an event
 */
void Actor::attachEvent(shared_ptr<Event> event)
{
    my_events.push_back(event);
}

/**
 * Detach an event
 */
void Actor::detachEvent(Event & event)
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
void Actor::notify(unsigned long step)
{
    for (
        vector<shared_ptr<Event> >::iterator eventIterator = my_events.begin();
        eventIterator != my_events.end();
        ++eventIterator
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
