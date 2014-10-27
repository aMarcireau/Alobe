#ifndef __ALOBE__MIGRATION_EVENT__
#define __ALOBE__MIGRATION_EVENT__

#include <map>
#include <string>

#include "periodicEvent.h"
#include "land.h"
#include "tile.h"

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
        void filteredAction(Land & land) ; // Get all the beings on the land to migrate
};

#endif // __ALOBE__MIGRATION_EVENT__
