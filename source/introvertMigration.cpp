#include "introvertMigration.h"

/**
 * Constructor
 */
IntrovertMigration::IntrovertMigration():
    Migration()
{
}

/**
 * Choose the tile where the being is willing to migrate
 */
Tile * IntrovertMigration::chooseTile(multimap<unsigned long, Tile *> & neighboringTilesBydistance) const
{
    unsigned long beingsTotal = 0;
    for (
        map<unsigned long, Tile *>::iterator tilesByDistanceIterator = neighboringTilesBydistance.begin();
        tilesByDistanceIterator != neighboringTilesBydistance.end();
        ++tilesByDistanceIterator
    ) {
        beingsTotal += tilesByDistanceIterator->second->getBeingsNumber();
    }

    vector<pair<Tile *, unsigned long> > tokenizedTiles;
    for (
        map<unsigned long, Tile *>::iterator tilesByDistanceIterator = neighboringTilesBydistance.begin();
        tilesByDistanceIterator != neighboringTilesBydistance.end();
        ++tilesByDistanceIterator
    ) {
        tokenizedTiles.push_back(make_pair(
            tilesByDistanceIterator->second,
            beingsTotal - tilesByDistanceIterator->second->getBeingsNumber() + 1
        ));
    }

    return my_tokenDistribution->getDecision(tokenizedTiles);
}
