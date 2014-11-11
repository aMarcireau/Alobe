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
    vector<Tile *> mostPopulatedTiles;
    unsigned long maximalBeingsNumber = 0;

    for (
        map<unsigned long, Tile *>::iterator tilesByDistanceIterator = neighboringTilesBydistance.begin();
        tilesByDistanceIterator != neighboringTilesBydistance.end();
        ++tilesByDistanceIterator
    ) {
        unsigned long tileBeingsNumber = tilesByDistanceIterator->second->getBeingsNumber();

        if (mostPopulatedTiles.empty()) {
            maximalBeingsNumber = tileBeingsNumber;
            mostPopulatedTiles.push_back(tilesByDistanceIterator->second);
        } else {
            if (tileBeingsNumber >= maximalBeingsNumber) {
                if (tileBeingsNumber > maximalBeingsNumber) {
                    mostPopulatedTiles.clear();
                    maximalBeingsNumber = tileBeingsNumber;
                }

                mostPopulatedTiles.push_back(tilesByDistanceIterator->second);
            }
        }
    }

    return mostPopulatedTiles[rand() %  mostPopulatedTiles.size()];
}
