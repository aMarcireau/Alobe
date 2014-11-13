#ifndef __ALOBE__GENDER__
#define __ALOBE__GENDER__

#include <string>

#include "behavior.h"

using namespace std;

/**
 * <<Abstract>> Gender
 * Inherits Behavior
 *
 * Get the being gender
 */
class Gender: public Behavior
{
    public:
        Gender();
        virtual ~Gender() = 0;
        virtual string get() const = 0; // Get the being gender
};

#endif // __ALOBE__GENDER__
