#ifndef __ALOBE__MATING_EVENT__
#define __ALOBE__MATING_EVENT__

#include <map>
#include <string>

#include "periodicEvent.h"
#include "land.h"
#include "tile.h"
#include "population.h"

/**
* MatingEvent
* Inherits PeriodicEvent
*
* Trigger the mating of beings on a land
*/
class MatingEvent : public PeriodicEvent
{
	public:
		MatingEvent();

	private:
		void filteredAction(Actor & actor); // Get all the nearest beings to meet and optionnaly mate
                                            // Actor must be a Population
};

#endif // __ALOBE__MATING_EVENT__
