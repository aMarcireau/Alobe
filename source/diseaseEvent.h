#ifndef __ALOBE__DISEASE_EVENT__
#define __ALOBE__DISEASE_EVENT__

#include <map>
#include <string>

#include "configuration.h"
#include "land.h"
#include "periodicEvent.h"
#include "tile.h"
#include "population.h"
#include "state.h"
#include "tabulatedDistribution.h"

/**
* DiseaseEvent
* Inherits PeriodicEvent
*
* Trigger the disease actions on the beings on a land
*/
class DiseaseEvent : public PeriodicEvent
{
    public:
        DiseaseEvent(
            unique_ptr<TabulatedDistribution> transmissionDistribution,
            unique_ptr<TabulatedDistribution> remissionDistribution,
            unique_ptr<TabulatedDistribution> deathDistribution
        );

    private:
        void filteredAction(Actor & actor);                            // Get all the nearest beings to share disease
                                                                       // Actor must be a Tile
        unique_ptr<TabulatedDistribution> my_transmissionDistribution;
        unique_ptr<TabulatedDistribution> my_remissionDistribution;
        unique_ptr<TabulatedDistribution> my_deathDistribution;
};

#endif // __ALOBE__DISEASE_EVENT__
