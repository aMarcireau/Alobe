#include "land.h"

/**
 * Constructor
 */
Land::Land(unsigned int width, unsigned int height):
    Actor(),
    my_width(width),
    my_height(height),
    my_tiles(vector<vector<unique_ptr<Tile> > >())
{
}

/**
 * Getter for the land width (number of tiles)
 */
unsigned int Land::getWidth() const
{
    return my_width;
}

/**
 * Getter for the land height (number of tiles)
 */
unsigned int Land::getHeight() const
{
    return my_height;
}

/**
 * Get tile by position
 */
Tile * Land::getTile(unsigned int x, unsigned int y) const
{
    return my_tiles[x][y].get();
}

/**
 * Get the number of tiles
 */
unsigned int Land::getTilesNumber() const
{
    return my_width * my_height;
}

/**
 * Generate the land tiles
 */
void Land::generate(Stepper & stepper)
{
    for (unsigned int y = 0; y < my_height; ++y) {
        vector<unique_ptr<Tile> > column;

        for (unsigned int x = 0; x < my_width; ++x) {
            column.push_back(make_unique<Tile>(x, y));
            stepper.attach(*(column.back().get()));
        }

        my_tiles.push_back(move(column));
    }
}
