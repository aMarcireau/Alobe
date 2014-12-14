#include "tile.h"

/**
 * Constructor
 */
Tile::Tile(unique_ptr<Graphics> graphics):
    Actor(move(graphics))
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
void Tile::attachBeing(Being * being)
{
    mod_beings.push_back(being);
}

/**
 * Detach a being
 */
bool Tile::detachBeing(Being * being)
{
    vector<Being *>::iterator position = find(mod_beings.begin(), mod_beings.end(), being);
    if (position != mod_beings.end()) {
        mod_beings.erase(position);

        return true;
    }

    return false;
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
    for (
        vector<Being *>::iterator beingIterator = my_beings.begin();
        beingIterator != my_beings.end();
        ++beingIterator
    ) {
        if (
            (*beingIterator)->getGraphics()->getXOffset() < getGraphics()->getXOffset() or
            (*beingIterator)->getGraphics()->getXOffset() > getGraphics()->getXOffset() + getGraphics()->getWidth() - BEING_RADIUS * 2
        ) {
            (*beingIterator)->getGraphics()->setXOffset(
                getGraphics()->getXOffset() + rand() % (getGraphics()->getWidth() - BEING_RADIUS * 2)
            );
        }

        if (
            (*beingIterator)->getGraphics()->getYOffset() < getGraphics()->getYOffset() or
            (*beingIterator)->getGraphics()->getYOffset() > getGraphics()->getYOffset() + getGraphics()->getHeight() - BEING_RADIUS * 2
        ) {
            (*beingIterator)->getGraphics()->setYOffset(
                getGraphics()->getYOffset() + rand() % (getGraphics()->getHeight() - BEING_RADIUS * 2)
            );
        }

        (*beingIterator)->getGraphics()->setXOffset(smoothedMove(
            (*beingIterator)->getGraphics()->getXOffset(),
            (*beingIterator)->getGraphics()->getXSpeed(),
            getGraphics()->getXOffset(),
            getGraphics()->getXOffset() + getGraphics()->getWidth() - BEING_RADIUS * 2,
            BEING_TURNOVER
        ));
        (*beingIterator)->getGraphics()->setYOffset(smoothedMove(
            (*beingIterator)->getGraphics()->getYOffset(),
            (*beingIterator)->getGraphics()->getYSpeed(),
            getGraphics()->getYOffset(),
            getGraphics()->getYOffset() + getGraphics()->getHeight() - BEING_RADIUS * 2,
            BEING_TURNOVER
        ));

        (*beingIterator)->getGraphics()->setWidth(BEING_RADIUS * 2);
        (*beingIterator)->getGraphics()->setHeight(BEING_RADIUS * 2);

        (*beingIterator)->trace();
    }
}

/**
 * Smoothed move next step
 */
unsigned long Tile::smoothedMove(unsigned long position, long long speed, unsigned long minimum, unsigned long maximum, float turnover) const
{
    if (position < minimum or position > maximum) {
        throw out_of_range("position");
    }
    if (turnover < 0 or turnover > 1) {
        throw out_of_range("turnover");
    }

    long long newSpeed;
    if (position == minimum) {
        if (rand() % 2 == 0) {
            newSpeed = 0;
        } else {
            newSpeed = 1;
        }
    } else if (position == maximum) {
        if (rand() % 2 == 0) {
            newSpeed = -1;
        } else {
            newSpeed = 0;
        }
    } else {
        if (rand() < turnover * RAND_MAX) {
            if (speed > 0 or speed < 0) {
                newSpeed = 0;
            } else {
                if (rand() % 2 == 0) {
                    newSpeed = -1;
                } else {
                    newSpeed = 1;
                }
            }
        } else {
            if (speed < 0) {
                newSpeed = -1;
            } else if (speed > 0) {
                newSpeed = 1;
            } else {
                newSpeed = 0;
            }
        }
    }

    return position + newSpeed;
}
