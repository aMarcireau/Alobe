#include "event.h"

/**
 * Constructor
 */
Event::Event(unsigned int step):
    triggerStep(step)
{
}

/**
 * Notification called by the Stepper
 */
void Event::notify(unsigned int step)
{
    if (step == this->getTriggerStep())
    {
        this->action();
    }
}

/**
 * Getter for triggerStep
 */
unsigned int Event::getTriggerStep()
{
    return triggerStep;
}
