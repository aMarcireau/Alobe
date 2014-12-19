#ifndef __ALOBE__BEHAVIOR__
#define __ALOBE__BEHAVIOR__

#include <memory>

class Being;

/**
 * <<Abstract>> Behavior
 *
 * Represent a behavior of a being
 */
class Behavior
{
    public:
        Behavior();
        virtual ~Behavior() = default;
};

#endif // ALOBE__BEHAVIOR
