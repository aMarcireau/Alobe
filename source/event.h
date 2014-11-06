#ifndef __ALOBE__EVENT__
#define __ALOBE__EVENT__

class Actor;

//using namespace std;

/**
 * <<Abstract>> Event
 *
 * An event is trigger by an actor, which passes itself and the current step to the event
 */
class Event
{
    public:
        Event(unsigned long step = 0);
        void action(Actor & actor, unsigned long step); // Trigger event action on an actor with a given step

    protected:
        virtual void filteredAction(Actor & actor) = 0; // Filtered action is called only if step == triggerStep
                                                        // This method is protected so that it can be called
                                                        // from abstract inherited classes
    protected:
        unsigned long my_step;                          // This property is protected so that it can be called
                                                        // from abstract inherited classes
};

#endif // __ALOBE__EVENT__
