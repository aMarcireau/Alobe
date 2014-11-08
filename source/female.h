#ifndef __ALOBE__FEMALE__
#define __ALOBE__FEMALE__

#include <string>

#include "being.h"

using namespace std;

/**
 * Female
 * Inherits Being
 *
 * Represent a female being
 */
class Female: virtual public Being
{
    public:
        string getGender(); // Get the being gender
};

#endif // __ALOBE__FEMALE__
