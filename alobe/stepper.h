#ifndef __ALOBE__STEPPER__
#define __ALOBE__STEPPER__

#include <vector>

#include "actor.h"

using namespace std;

/**
 * Stepper
 *
 * A stepper will trigger its observers (Actor objects) after each step.
 */
class Stepper
{
    public:
        Stepper();
        void increment();           // Increment the stepper value and notify the attached actors
        void reset();               // Reset the stepper value
        unsigned int getStep();     // Get the current step
        void attach(Actor & actor); // Attach an actor
        void detach(Actor & actor); // Detach an actor

    private:
        unsigned int _step;
        vector<Actor *> _actors;
};

#endif // __ALOBE__STEPPER__
