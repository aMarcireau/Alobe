#ifndef __alobe__event__
#define __alobe__event__

/**
 * <<Abstract>> Event
 *
 * An event is trigger by the Stepper it is attached to, through its notify method.
 * The action() method will be called if the passed step value is equal to triggerStep.
 */
class Event
{
    public:
        Event(unsigned int step = 0);   // Constructor
        void notify(unsigned int step); // Notification called by the Stepper
        unsigned int getTriggerStep();  // Getter for triggerStep

    protected:
        virtual void action() = 0;      // Action called by notify()

    private:
        unsigned int triggerStep;       // Store the trigger step value
};

#endif /* defined(__alobe__event__) */
