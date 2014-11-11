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
    vector<Tile *> leastPopulatedTiles;
    unsigned long minimalBeingsNumber = 0;

    for (
        map<unsigned long, Tile *>::iterator tilesByDistanceIterator = neighboringTilesBydistance.begin();
        tilesByDistanceIterator != neighboringTilesBydistance.end();
        ++tilesByDistanceIterator
    ) {
        unsigned long tileBeingsNumber = tilesByDistanceIterator->second->getBeingsNumber();

        if (leastPopulatedTiles.empty()) {
            minimalBeingsNumber = tileBeingsNumber;
            leastPopulatedTiles.push_back(tilesByDistanceIterator->second);
        } else {
            if (tileBeingsNumber <= minimalBeingsNumber) {
                if (tileBeingsNumber < minimalBeingsNumber) {
                    leastPopulatedTiles.clear();
                    minimalBeingsNumber = tileBeingsNumber;
                }

                leastPopulatedTiles.push_back(tilesByDistanceIterator->second);
            }
        }
    }

    return leastPopulatedTiles[rand() %  leastPopulatedTiles.size()];
}
