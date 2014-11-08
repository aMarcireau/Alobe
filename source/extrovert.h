#ifndef __ALOBE__EXTROVERT__
#define __ALOBE__EXTROVERT__

#include <string>
#include <stdlib.h>

#include "being.h"
#include "tile.h"

using namespace std;

/**
 * Extrovert
 * Inherits Being
 *
 * Extrovert beings migrate to one of the tiles with the largest beings number
 */
class Extrovert: virtual public Being
{
    public:
        Tile * getMigration(multimap<unsigned long, Tile *> neighboringTilesBydistance); // Get the tile where the being is willing to migrate
};

#endif // __ALOBE__EXTROVERT__
