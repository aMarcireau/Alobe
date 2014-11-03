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
vector<Being *> Tile::getBeings() const
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
void Tile::attachBeing(Being & being)
{
    mod_beings.push_back(&being);
}

/**
 * Detach a being
 */
void Tile::detachBeing(Being & being)
{
    for (
        vector<Being *>::iterator beingIterator = mod_beings.begin();
        beingIterator != mod_beings.end();
    ) {
        if (*beingIterator == &being) {
            mod_beings.erase(beingIterator);
        } else {
            ++beingIterator;
        }
    }
}

/**
 * Apply changes after a step
 */
void Tile::applyChanges(Stepper & stepper)
{
    my_beings = mod_beings;
}
