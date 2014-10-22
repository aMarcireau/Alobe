#ifndef __ALOBE__STATE__
#define __ALOBE__STATE__

#include <string>

using namespace std;

/**
 * State
 *
 * Represent the state of a being (related to a given property, such as remaining lifetime)
 */
class State
{
    public:
        State(string id, unsigned long property);
        string getId() const;                     // Getter fot the state identifier
        unsigned long getProperty() const;        // Getter for the state property
        void applyChanges();                      // Apply changes after a step
        void decrement(unsigned long value = 1);  // Decrement the state property. The property is set to 0
                                                  // if it reaches a negative value

    private:
        string my_id;
        unsigned long my_property;
        unsigned long mod_property;
};

#endif // __ALOBE__STATE__
