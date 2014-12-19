#include "extrovertMigration.h"

/**
 * Constructor
 */
ExtrovertMigration::ExtrovertMigration():
    Migration()
{
}

/**
 * Choose the tile where the being is willing to migrate
 */
Tile * ExtrovertMigration::chooseTile(multimap<unsigned long, Tile *> & neighboringTilesBydistance) const
{
    vector<pair<Tile *, unsigned long> > tokenizedTiles;

    for (
        map<unsigned long, Tile *>::iterator tilesByDistanceIterator = neighboringTilesBydistance.begin();
        tilesByDistanceIterator != neighboringTilesBydistance.end();
        ++tilesByDistanceIterator
    ) {
        tokenizedTiles.push_back(make_pair(tilesByDistanceIterator->second, tilesByDistanceIterator->second->getBeingsNumber() + 1));
    }

    return my_tokenDistribution->getDecision(tokenizedTiles);
}

/**
 * Get migration type
 */
string ExtrovertMigration::getType() const
{
    return "extrovert";
}
