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
        State(string id);
        string getId() const; // Getter fot the state identifier

    private:
        string my_id;

};

#endif // __ALOBE__STATE__
