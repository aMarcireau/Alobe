#ifndef __ALOBE__BEHAVIOUR__
#define __ALOBE__BEHAVIOUR__

class Being;

/**
 * <<Abstract>> Behaviour
 *
 * An event is trigger by an actor, which passes itself and the current step to the event
 */
class Behaviour
{
    public:
        Behaviour();
        virtual void action(Being & being) = 0; // Trigger behaviour action on a a being
};

#endif // __ALOBE__BEHAVIOUR__
