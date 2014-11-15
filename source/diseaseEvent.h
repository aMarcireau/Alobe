#ifndef __ALOBE__DISEASE_EVENT__
#define __ALOBE__DISEASE_EVENT__

#include <map>
#include <string>
#include "land.h"
#include "periodicEvent.h"
#include "tile.h"
#include "population.h"
#include "state.h"

/**
* DiseaseEvent
* Inherits PeriodicEvent
*
* Trigger the disease actions on the beings on a land
*/
class DiseaseEvent : public PeriodicEvent
{
public:
	DiseaseEvent();

private:
	void filteredAction(Actor & actor); // Get all the nearest beings to share disease
	// Actor must be a Population
};

#endif // __ALOBE__DISEASE_EVENT__
