#ifndef __ALOBE__MALE__
#define __ALOBE__MALE__

#include <string>

#include "being.h"

using namespace std;

/**
 * Male
 * Inherits Being
 *
 * Represent a male being
 */
class Male: virtual public Being
{
    public:
        string getGender(); // Get the being gender
};

#endif // __ALOBE__MALE__
