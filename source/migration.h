#ifndef __ALOBE__MIGRATION__
#define __ALOBE__MIGRATION__

#include "behavior.h"
#include "tile.h"

using namespace std;

/**
 * <<Abstract>> Migration
 * Inherits Behavior
 *
 * Determine the tile where the being is willing to migrate
 */
class Migration: public Behavior
{
    public:
        Migration();
        virtual Tile * chooseTile(multimap<unsigned long, Tile *> & neighboringTilesBydistance) const = 0; // Choose the tile where the being is willing to migrate
};

#endif // __ALOBE__MIGRATION__
