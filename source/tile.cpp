#include "tile.h"

/**
 * Constructor
 */
Tile::Tile(shared_ptr<GraphicsWindow> graphicsWindow):
    Actor(graphicsWindow)
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
    vector<Being *> keptBeings;
    for (
        vector<Being *>::iterator beingIterator = mod_beings.begin();
        beingIterator != mod_beings.end();
        ++beingIterator
    ) {
        if (*beingIterator != &being) {
            keptBeings.push_back(*beingIterator);
        }
    }

    mod_beings = keptBeings;
}

/**
 * Apply changes after a step
 */
void Tile::applyChanges(Stepper & stepper)
{
    my_beings = mod_beings;
}

/**
 * Trace the tile
 */
void Tile::trace()
{
}
