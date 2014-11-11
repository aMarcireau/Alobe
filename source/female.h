#ifndef __ALOBE__FEMALE__
#define __ALOBE__FEMALE__

#include <string>

#include "gender.h"

using namespace std;

/**
 * Female
 * Inherits Gender
 *
 * Represent a female gender
 */
class Female: public Gender
{
    public:
        Female();
        string get() const; // Get the being gender
};

#endif // __ALOBE__FEMALE__
