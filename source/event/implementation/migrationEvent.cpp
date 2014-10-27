#include "migrationEvent.h"

/**
 * Constructor
 */
MigrationEvent::MigrationEvent():
    PeriodicEvent()
{
}

/**
 * Get all the beings on the land to migrate
 */
void MigrationEvent::filteredAction(Land & land)
{
    for (unsigned long x = 0; x < land.getWidth(); ++x) {
        for (unsigned long y = 0; y < land.getHeight(); ++y) {
            map<string, Tile *> neighboringTiles = land.getNeighboringTiles(x, y);
            vector<shared_ptr<Being> > beings = neighboringTiles["here"]->getBeings();

            for (
                vector<shared_ptr<Being> >::iterator beingIterator = beings.begin();
                beingIterator != beings.end();
            ) {
                if ((*beingIterator).get()->isDead()) {
                    neighboringTiles["here"]->detachBeing(*(*beingIterator));
                } else {

                    string direction = (*beingIterator)->migrate(neighboringTiles);
                    if (direction != "here") {
                        neighboringTiles[direction]->attachBeing((*beingIterator));
                        neighboringTiles["here"]->detachBeing(*(*beingIterator));
                    }

                    ++beingIterator;
                }
            }
        }
    }
}
