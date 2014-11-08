#ifndef __ALOBE__INTROVERT__
#define __ALOBE__INTROVERT__

#include <string>
#include <stdlib.h>

#include "being.h"
#include "tile.h"

using namespace std;

/**
 * Introvert
 * Inherits Being
 *
 * Introvert beings migrate to one of the tiles with the smallest beings number
 */
class Introvert: virtual public Being
{
    public:
        Tile * getMigration(multimap<unsigned long, Tile *> neighboringTilesBydistance); // Get the tile where the being is willing to migrate
};

#endif // __ALOBE__INTROVERT__
