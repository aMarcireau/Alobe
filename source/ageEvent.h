#ifndef __ALOBE__AGE_EVENT__
#define __ALOBE__AGE_EVENT__

#include <string>

#include "periodicEvent.h"
#include "being.h"
#include "population.h"
#include "tabulatedDistribution.h"

/**
 * AgeEvent
 * Inherits PeriodicEvent
 *
 * Age all the beings of a population
 */
class AgeEvent: public PeriodicEvent
{
    public:
        AgeEvent(unique_ptr<TabulatedDistribution> deathDistribution);

    private:
        void filteredAction(Actor & actor);                     // Age all the beings of the population
                                                                // Actor must be a Population
        unique_ptr<TabulatedDistribution> my_deathDistribution;
};

#endif // __ALOBE__AGE_EVENT__
