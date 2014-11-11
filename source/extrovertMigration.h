#ifndef __ALOBE__EXTROVERT_MIGRATION__
#define __ALOBE__EXTROVERT_MIGRATION__

#include <stdlib.h>

#include "migration.h"
#include "tile.h"

using namespace std;

/**
 * ExtrovertMigration
 * Inherits Migration
 *
 * Extrovert beings migrate to one of the tiles with the largest beings number
 */
class ExtrovertMigration: public Migration
{
    public:
        ExtrovertMigration();
        Tile * chooseTile(multimap<unsigned long, Tile *> & neighboringTilesBydistance) const; // Choose the tile where the being is willing to migrate
};

#endif // __ALOBE__EXTROVERT_MIGRATION__
