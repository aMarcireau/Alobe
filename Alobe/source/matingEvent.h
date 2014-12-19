#ifndef __ALOBE__MATING_EVENT__
#define __ALOBE__MATING_EVENT__

#include <map>
#include <string>
#include <algorithm>

#include "periodicEvent.h"
#include "land.h"
#include "tile.h"
#include "population.h"
#include "tabulatedDistribution.h"
#include "configuration.h"
#include "gender.h"

/**
* MatingEvent
* Inherits PeriodicEvent
*
* Trigger the mating of beings on a land
*/
class MatingEvent : public PeriodicEvent
{
	public:
		MatingEvent(unique_ptr<TabulatedDistribution> willingToMateDistribution);

	private:
		void filteredAction(Actor & actor);                             // Get all the nearest beings to meet and optionnaly mate
                                                                        // Actor must be a Population
        unique_ptr<TabulatedDistribution> my_willingToMateDistribution;
};

#endif // __ALOBE__MATING_EVENT__
