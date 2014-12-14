#include "eventManager.h"

/**
 * Constructor
 */
EventManager::EventManager():
    my_targetBeing(nullptr)
{
}

/**
 * Set the color of each being
 */
void EventManager::setBeingsColors(bool isMouseClicked, unsigned long xMousePosition, unsigned long yMousePosition, Land & land)
{
    for (unsigned long x = 0; x < land.getWidth(); ++x) {
        for (unsigned long y = 0; y < land.getHeight(); ++y) {
            vector<Being *> beings = land.getTile(x, y)->getBeings();

            for (
                vector<Being *>::reverse_iterator beingIterator = beings.rbegin();
                beingIterator != beings.rend();
                ++beingIterator
            ) {
                if ((*beingIterator)->hasState("sick")) {
                    (*beingIterator)->getGraphics()->setColor(SICK_BEING_COLOR);
                } else {
                    (*beingIterator)->getGraphics()->setColor(BEING_COLOR);
                }
            }
        }
    }

    if (isMouseClicked) {
        bool beingFound = false;

        for (unsigned long x = 0; x < land.getWidth(); ++x) {
            for (unsigned long y = 0; y < land.getHeight(); ++y) {
                Tile * tile = land.getTile(x, y);

                if (
                    xMousePosition >= tile->getGraphics()->getXOffset() &&
                    xMousePosition <= tile->getGraphics()->getXOffset() + tile->getGraphics()->getWidth() &&
                    yMousePosition >= tile->getGraphics()->getYOffset() &&
                    yMousePosition <= tile->getGraphics()->getYOffset() + tile->getGraphics()->getHeight()
                ) {
                    vector<Being *> beings = tile->getBeings();

                    for (
                        vector<Being *>::reverse_iterator beingIterator = beings.rbegin();
                        beingIterator != beings.rend();
                        ++beingIterator
                    ) {
                        if (
                            xMousePosition >= (*beingIterator)->getGraphics()->getXOffset() &&
                            xMousePosition <= (*beingIterator)->getGraphics()->getXOffset() + (*beingIterator)->getGraphics()->getWidth() &&
                            yMousePosition >= (*beingIterator)->getGraphics()->getYOffset() &&
                            yMousePosition <= (*beingIterator)->getGraphics()->getYOffset() + (*beingIterator)->getGraphics()->getHeight()
                        ) {
                            if ((*beingIterator)->hasState("sick")) {
                                (*beingIterator)->getGraphics()->setColor(ON_CLICK_SICK_BEING_COLOR);
                            } else {
                                (*beingIterator)->getGraphics()->setColor(ON_CLICK_BEING_COLOR);
                            }
                            my_targetBeing = (*beingIterator);
                            beingFound = true;
                            break;
                        }
                    }
                }
                if (beingFound) {
                    break;
                }
            }
            if (beingFound) {
                break;
            }
        }
    }
}

/**
 * Set the color of each being
 */
Being * EventManager::getTargetBeing()
{
    return my_targetBeing;
}
