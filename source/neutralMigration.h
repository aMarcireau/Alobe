#ifndef __ALOBE__NEUTRAL__
#define __ALOBE__NEUTRAL__

#include <stdlib.h>

#include "migration.h"
#include "tile.h"

using namespace std;

/**
 * NeutralMigration
 * Inherits Migration
 *
 * Neutral beings migrate to a random tile
 */
class NeutralMigration: public Migration
{
    public:
        NeutralMigration();
        Tile * chooseTile(multimap<unsigned long, Tile *> & neighboringTilesBydistance) const; // Choose the tile where the being is willing to migrate
};

#endif // __ALOBE__NEUTRAL__
