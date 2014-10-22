#include "land.h"

/**
 * Constructor
 */
Land::Land(unsigned long width, unsigned long height):
    Actor(),
    my_width(width),
    my_height(height),
    my_tiles(vector<vector<unique_ptr<Tile> > >())
{
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
 * Generate the land tiles
 */
void Land::generate(Stepper & stepper)
{
    for (unsigned long x = 0; x < my_width; ++x) {
        vector<unique_ptr<Tile> > column;

        for (unsigned long y = 0; y < my_height; ++y) {
            column.push_back(make_unique<Tile>());
            stepper.attach(*(column.back().get()));
        }

        my_tiles.push_back(move(column));
    }
}

/**
 * Generate the land beings migration
 */
void Land::migrate()
{
    for (unsigned long y = 0; y < my_height; ++y) {
        for (unsigned long x = 0; x < my_width; ++x) {

            this->getTile(x, y)->migrate(this->getTileNeighbors(x, y));
        }
    }
}

/**
 * Retrieve a tile neighboring tiles
 */
map<string, Tile *> Land::getTileNeighbors(unsigned long x, unsigned long y) const
{
    map<string, Tile *> neighboringTiles;

    unsigned long xEast  = ((x == my_width - 1)  ? 0         : x + 1);
    unsigned long xWest  = ((x == 0)             ? my_width  : x - 1);
    unsigned long yNorth = ((y == my_height - 1) ? 0         : y + 1);
    unsigned long ySouth = ((y == 0)             ? my_height : y + 1);

    neighboringTiles.insert(pair<string, Tile *>("East",  this->getTile(xEast, y)));
    neighboringTiles.insert(pair<string, Tile *>("West",  this->getTile(xWest, y)));
    neighboringTiles.insert(pair<string, Tile *>("North", this->getTile(x, yNorth)));
    neighboringTiles.insert(pair<string, Tile *>("South", this->getTile(x, ySouth)));

    return neighboringTiles;
}

void Land::applyChanges()
{
    for (unsigned long y = 0; y < my_height; ++y) {
        for (unsigned long x = 0; x < my_width; ++x) {

            this->getTile(x, y)->applyChanges();
        }
    }
}
