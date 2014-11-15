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
    Land & land(dynamic_cast<Land &>(actor));

    for (unsigned long x = 0; x < land.getWidth(); ++x) {
        for (unsigned long y = 0; y < land.getHeight(); ++y) {
            multimap<unsigned long, Tile *> neighboringTiles = land.getNeighboringTilesByDistance(x, y);

            vector<Being *> beings = land.getTile(x, y)->getBeings();
            for (
                vector<Being *>::iterator beingIterator = beings.begin();
                beingIterator != beings.end();
                ++beingIterator
            ) {
                Tile * chosenTile = dynamic_cast<Migration &>(*((*beingIterator)->getBehavior("migration"))).chooseTile(neighboringTiles);

                land.getTile(x, y)->detachBeing(*(*beingIterator));
                chosenTile->attachBeing(*(*beingIterator));
            }
        }
    }
}
