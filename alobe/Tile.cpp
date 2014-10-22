#include "tile.h"

/**
 * Constructor
 */
Tile::Tile():
    Actor()
{
}

/**
 * Getter for the beings
 */
vector<shared_ptr<Being> > Tile::getBeings() const
{
    return my_beings;
}

/**
 * Retrieve the number of beings
 */
unsigned long Tile::getBeingsNumber() const
{
    return my_beings.size();
}

/**
 * Attach a being
 */
void Tile::attachBeing(shared_ptr<Being> being)
{
    mod_beings.push_back(being);
}

/**
 * Detach a being
 */
void Tile::detachBeing(Being & being)
{
    for (
        vector<shared_ptr<Being> >::iterator beingIterator = mod_beings.begin();
        beingIterator != mod_beings.end();
    ) {
        if ((*beingIterator).get() == &being) {
            mod_beings.erase(beingIterator);
        } else {
            ++beingIterator;
        }
    }
}

/**
 * Apply changes after a step
 */
void Tile::applyChanges()
{
    my_beings = mod_beings;
}

/**
 * Generate the tile beings migration
 * 4 neighboring tiles are expected,
 * with keys 'N', 'S', 'E' and 'W'
 */
void Tile::migrate(map<string, Tile *> neighborsTiles)
{
    map<string, unsigned long> neighborsBeingNumbers;
    neighborsBeingNumbers.insert(pair<string, unsigned long>("here", this->getBeingsNumber()));
    for (
        map<string, Tile *>::iterator neighborsTilesIterator = neighborsTiles.begin();
        neighborsTilesIterator != neighborsTiles.end();
        ++neighborsTilesIterator
    ) {
        neighborsBeingNumbers.insert(pair<string, unsigned long>(
            neighborsTilesIterator->first,
            neighborsTilesIterator->second->getBeingsNumber()
        ));
    }

    for (
        vector<shared_ptr<Being> >::iterator beingIterator = mod_beings.begin();
        beingIterator != mod_beings.end();
    ) {
        if ((*beingIterator).get()->isDead()) {
            mod_beings.erase(beingIterator);
        } else {
            string direction = (*beingIterator)->migrate(neighborsBeingNumbers);
            if (direction != "Here") {
                neighborsTiles[direction]->attachBeing((*beingIterator));
                this->detachBeing(*(*beingIterator));
            }

            ++beingIterator;
        }
    }
}
