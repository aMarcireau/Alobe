#ifndef __ALOBE__STATE__
#define __ALOBE__STATE__

#include <string>

using namespace std;

/**
 * State
 *
 * Represent a state of a being (related to a given value, such as remaining lifetime)
 */
class State
{
    public:
        State(unsigned long value);
        unsigned long getValue() const;           // Getter for the state value
        void applyChanges();                      // Apply changes after a step
        void decrement(unsigned long amount = 1); // Decrement the state value. The value is set to 0
                                                  // if it reaches a negative value

    private:
        unsigned long my_value;
        unsigned long mod_value;
};

#endif // __ALOBE__STATE__
