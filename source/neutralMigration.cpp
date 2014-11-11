#include "neutralMigration.h"

/**
 * Constructor
 */
NeutralMigration::NeutralMigration():
    Migration()
{
}

/**
 * Choose the tile where the being is willing to migrate
 */
Tile * NeutralMigration::chooseTile(multimap<unsigned long, Tile *> & neighboringTilesBydistance) const
{
    multimap<unsigned long, Tile *>::iterator tilesByDistanceIterator = neighboringTilesBydistance.begin();
    advance(tilesByDistanceIterator, rand() % neighboringTilesBydistance.size());

    return tilesByDistanceIterator->second;
}
