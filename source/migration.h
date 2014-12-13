#ifndef __ALOBE__MIGRATION__
#define __ALOBE__MIGRATION__

#include "behavior.h"
#include "tile.h"
#include "tokenDistribution.h"
#include "tokenDistribution.cpp"

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
        virtual ~Migration() = default;
        virtual Tile * chooseTile(multimap<unsigned long, Tile *> & neighboringTilesBydistance) const = 0; // Choose the tile where the being is willing to migrate
    protected:
        unique_ptr<TokenDistribution<Tile *> > my_tokenDistribution;
};

#endif // __ALOBE__MIGRATION__
