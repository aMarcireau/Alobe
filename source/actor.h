#ifndef __ALOBE__ACTOR__
#define __ALOBE__ACTOR__

#include <vector>
#include <memory>

#include "event.h"

class Stepper;

using namespace std;

/**
 * <<Abstract>> Actor
 *
 * Actor in the simulation
 */
class Actor
{
    public:
        Actor();
        void attachEvent(shared_ptr<Event> event); // Attach an event
        void detachEvent(Event & event);           // Detach an event
        void notify(unsigned long step);           // Notification called by a Stepper object
        bool isDead();                             // Is the actor dead?
        virtual void applyChanges() = 0;           // Apply changes after a step

    private:
        vector<shared_ptr<Event> > my_events;
};

#endif // __ALOBE__ACTOR__
