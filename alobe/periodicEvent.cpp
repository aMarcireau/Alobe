#include "periodicEvent.h"

/**
 * Constructor
 */
PeriodicEvent::PeriodicEvent(unsigned int step, unsigned int period):
    Event(step),
    triggerPeriod(period)
{
}

/**
 * Notification called by the Stepper
 */
void PeriodicEvent::notify(unsigned int step)
{
    if (step >= this->getTriggerStep() and (step - this->getTriggerStep()) % this->getTriggerPeriod() == 0)
    {
        this->action();
    }
}

/**
 * Getter for triggerPeriod
 */
unsigned int PeriodicEvent::getTriggerPeriod()
{
    return triggerPeriod;
}
