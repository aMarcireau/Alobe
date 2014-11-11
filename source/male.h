#ifndef __ALOBE__MALE__
#define __ALOBE__MALE__

#include <string>

#include "gender.h"

using namespace std;

/**
 * Male
 * Inherits Gender
 *
 * Represent a male gender
 */
class Male: public Gender
{
    public:
        Male();
        string get() const; // Get the being gender
};

#endif // __ALOBE__MALE__
