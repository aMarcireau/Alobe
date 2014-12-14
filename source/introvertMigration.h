#ifndef __ALOBE__INTROVERT_MIGRATION__
#define __ALOBE__INTROVERT_MIGRATION__

#include <stdlib.h>

#include "migration.h"
#include "tile.h"

using namespace std;

/**
 * INtrovertMigration
 * Inherits Migration
 *
 * INtrovert beings migrate to one of the tiles with the smallest beings number
 */
class IntrovertMigration: public Migration
{
    public:
        IntrovertMigration();
        Tile * chooseTile(multimap<unsigned long, Tile *> & neighboringTilesBydistance) const; // Choose the tile where the being is willing to migrate
        string getType() const;                                                                // Get migration type
};

#endif // __ALOBE__INTROVERT_MIGRATION__
