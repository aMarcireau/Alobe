#ifndef __ALOBE__ACTOR__
#define __ALOBE__ACTOR__

#include <vector>
#include <memory>

#include "event.h"

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
        void attach(shared_ptr<Event> event); // Attach an event
        void detach(Event & event);           // Detach an event
        void notify(unsigned int step);       // Notification called by a Stepper object
        bool isDead();                        // Is the actor dead?

    private:
        vector<shared_ptr<Event> > my_events;
};

#endif // __ALOBE__ACTOR__
