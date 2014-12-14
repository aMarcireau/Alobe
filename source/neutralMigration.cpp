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
    vector<pair<Tile *, unsigned long> > tokenizedTiles;

    for (
        map<unsigned long, Tile *>::iterator tilesByDistanceIterator = neighboringTilesBydistance.begin();
        tilesByDistanceIterator != neighboringTilesBydistance.end();
        ++tilesByDistanceIterator
    ) {
        tokenizedTiles.push_back(make_pair(tilesByDistanceIterator->second, 1));
    }

    return my_tokenDistribution->getDecision(tokenizedTiles);
}

/**
 * Get migration type
 */
string NeutralMigration::getType() const
{
    return "neutral";
}
