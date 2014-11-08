#include "neutral.h"

/**
 * Get the tile where the being is willing to migrate
 */
Tile * Neutral::getMigration(multimap<unsigned long, Tile *> neighboringTilesBydistance)
{
    multimap<unsigned long, Tile *>::iterator tilesByDistanceIterator = neighboringTilesBydistance.begin();
    advance(tilesByDistanceIterator, rand() % neighboringTilesBydistance.size());

    return tilesByDistanceIterator->second;
}
