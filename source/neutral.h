#ifndef __ALOBE__NEUTRAL__
#define __ALOBE__NEUTRAL__

#include <string>
#include <stdlib.h>

#include "being.h"
#include "tile.h"

using namespace std;

/**
 * Neutral
 * Inherits Being
 *
 * Neutral beings migrate to a random tile
 */
class Neutral: virtual public Being
{
    public:
        Tile * getMigration(multimap<unsigned long, Tile *> neighboringTilesBydistance); // Get the tile where the being is willing to migrate
};

#endif // __ALOBE__NEUTRAL__
