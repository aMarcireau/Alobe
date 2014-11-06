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
void MigrationEvent::filteredAction(Actor & actor)
{

    /* TODO: REFACTOR WITH BEING BEHAVIOURS

    Land & land(dynamic_cast<Land &>(actor));

    for (unsigned long x = 0; x < land.getWidth(); ++x) {
        for (unsigned long y = 0; y < land.getHeight(); ++y) {
            map<string, Tile *> neighboringTiles = land.getNeighboringTiles(x, y);
            vector<Being *> beings = neighboringTiles["here"]->getBeings();

            for (
                vector<Being *>::iterator beingIterator = beings.begin();
                beingIterator != beings.end();
                ++beingIterator
            ) {
                string direction = (*beingIterator)->migrate(neighboringTiles);
                if (direction != "here") {
                    neighboringTiles[direction]->attachBeing(*(*beingIterator));
                    neighboringTiles["here"]->detachBeing(*(*beingIterator));
                }
            }
        }
    }
    
    */
}
