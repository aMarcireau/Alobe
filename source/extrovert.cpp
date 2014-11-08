#include "extrovert.h"

/**
 * Get the tile where the being is willing to migrate
 */
Tile * Extrovert::getMigration(multimap<unsigned long, Tile *> neighboringTilesBydistance)
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
