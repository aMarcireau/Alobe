#include "land.h"

/**
 * Constructor
 */
Land::Land(unique_ptr<Graphics> graphics, unsigned long width, unsigned long height):
    Actor(move(graphics)),
    my_width(width),
    my_height(height),
    my_tiles(vector<vector<unique_ptr<Tile> > >()),
    mod_tiles(vector<vector<unique_ptr<Tile> > >())
{
    for (unsigned long x = 0; x < my_width; ++x) {
        vector<unique_ptr<Tile> > column;

        for (unsigned long y = 0; y < my_height; ++y) {
            column.push_back(make_unique<Tile>(getGraphics()->clone()));
        }

        mod_tiles.push_back(move(column));
    }
}

/**
 * Getter for the land width (number of tiles)
 */
unsigned long Land::getWidth() const
{
    return my_width;
}

/**
 * Getter for the land height (number of tiles)
 */
unsigned long Land::getHeight() const
{
    return my_height;
}

/**
 * Get tile by position
 */
Tile * Land::getTile(unsigned long x, unsigned long y) const
{
    if (x >= my_width) {
        throw out_of_range("x");
    }

    if (y >= my_height) {
        throw out_of_range("y");
    }

    return my_tiles[x][y].get();
}

/**
 * Get the number of tiles
 */
unsigned long Land::getTilesNumber() const
{
    return my_width * my_height;
}

/**
 * Retrieve a tile neighboring tiles
 */
multimap<unsigned long, Tile *> Land::getNeighboringTilesByDistance(unsigned long x, unsigned long y, unsigned long distance) const
{
    long long ll_x = static_cast<long long>(x);
    long long ll_y = static_cast<long long>(y);
    long long ll_distance = static_cast<long long>(distance);
    long long ll_width = static_cast<long long>(my_width);
    long long ll_height = static_cast<long long>(my_height);

    multimap<unsigned long, Tile *> neighboringTilesByDistance;

    for (long long ll_xDelta = 0; ll_xDelta <= ll_distance; ++ll_xDelta) {
        for (long long ll_yDelta = 0; ll_yDelta <= (ll_distance - ll_xDelta); ++ll_yDelta) {

            unsigned long deltaDistance = static_cast<unsigned long>(ll_xDelta + ll_yDelta);

            neighboringTilesByDistance.insert(pair<unsigned long, Tile *>(
                deltaDistance,
                getTile(
                    static_cast<unsigned long>(llModulo(ll_x - ll_xDelta, ll_width)),
                    static_cast<unsigned long>(llModulo(ll_y - ll_yDelta, ll_height))
                )
            ));

            if (ll_xDelta != 0 || ll_yDelta != 0) {
                neighboringTilesByDistance.insert(pair<unsigned long, Tile *>(
                    deltaDistance,
                    getTile(
                        static_cast<unsigned long>(llModulo(ll_x + ll_xDelta, ll_width)),
                        static_cast<unsigned long>(llModulo(ll_y + ll_yDelta, ll_height))
                    )
                ));
            }
        }
    }

    return neighboringTilesByDistance;
}

/**
 * Apply changes after a step
 */
void Land::applyChanges(Stepper & stepper)
{
    if (!mod_tiles.empty()) {

        for (
            vector<vector<unique_ptr<Tile> > >::iterator columnIterator = mod_tiles.begin();
            columnIterator != mod_tiles.end();
            ++columnIterator
        ) {

            for (
                vector<unique_ptr<Tile> >::iterator tileIterator = columnIterator->begin();
                tileIterator != columnIterator->end();
                ++tileIterator
            ) {
                stepper.attach(*((*tileIterator).get()));
            }
        }

        my_tiles = move(mod_tiles);
        mod_tiles = vector<vector<unique_ptr<Tile> > >();
    }

    for (unsigned long x = 0; x < my_width; ++x) {
        for (unsigned long y = 0; y < my_height; ++y) {
            getTile(x, y)->applyChanges(stepper);
        }
    }
}

/**
 * Trace the land
 */
void Land::trace()
{
    getGraphics()->drawStripes(
        0, getGraphics()->getGraphicsWindow()->getWidth(),
        0, getGraphics()->getGraphicsWindow()->getHeight(),
        "horizontal",
        my_height,
        2,
        0x808080
    );
    getGraphics()->drawStripes(
        0, getGraphics()->getGraphicsWindow()->getWidth(),
        0, getGraphics()->getGraphicsWindow()->getHeight(),
        "vertical",
        my_width,
        2,
        0x808080
    );
    for (unsigned long x = 0; x < my_width; ++x) {
        for (unsigned long y = 0; y < my_height; ++y) {
            getTile(x, y)->getGraphics()->setXOffset(intervalToCoordinate(
                getGraphics()->getXOffset(),
                getGraphics()->getGraphicsWindow()->getWidth(),
                my_width,
                x
            ));
            getTile(x, y)->getGraphics()->setYOffset(intervalToCoordinate(
                getGraphics()->getYOffset(),
                getGraphics()->getGraphicsWindow()->getHeight(),
                my_height,
                y
            ));
            getTile(x, y)->trace();
        }
    }
}
