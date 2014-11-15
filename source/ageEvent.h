#ifndef __ALOBE__AGE_EVENT__
#define __ALOBE__AGE_EVENT__

#include <string>

#include "periodicEvent.h"
#include "being.h"
#include "population.h"

/**
 * AgeEvent
 * Inherits PeriodicEvent
 *
 * Age all the beings of a population
 */
class AgeEvent: public PeriodicEvent
{
    public:
        AgeEvent();

    private:
        void filteredAction(Actor & actor) ; // Age all the beings of the population
                                             // Actor must be a Population
};

#endif // __ALOBE__AGE_EVENT__
