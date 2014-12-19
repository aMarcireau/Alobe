#ifndef __ALOBE__MIGRATION_EVENT__
#define __ALOBE__MIGRATION_EVENT__

#include <map>
#include <string>

#include "periodicEvent.h"
#include "land.h"
#include "tile.h"
#include "migration.h"

/**
 * MigrationEvent
 * Inherits PeriodicEvent
 *
 * Trigger the migration on a land
 */
class MigrationEvent: public PeriodicEvent
{
    public:
        MigrationEvent();

    private:
        void filteredAction(Actor & actor); // Get all the beings on the land to migrate
                                            // Actor must be a Land
};

#endif // __ALOBE__MIGRATION_EVENT__
