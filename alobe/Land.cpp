#include "land.h"

/**
 * Constructor
 */
Land::Land(unsigned int width, unsigned int height):
    Actor(),
    _width(width),
    _height(height),
    _tiles(vector<vector<unique_ptr<Tile> > >())
{
}

/**
 * Getter for the land width (number of tiles)
 */
unsigned int Land::getWidth() const
{
    return _width;
}

/**
 * Getter for the land height (number of tiles)
 */
unsigned int Land::getHeight() const
{
    return _height;
}

/**
 * Get tile by position
 */
Tile * Land::getTile(unsigned int x, unsigned int y) const
{
    return _tiles[x][y].get();
}

/**
 * Get the number of tiles
 */
unsigned int Land::getTilesNumber() const
{
    return _width * _height;
}

/**
 * Generate the land tiles
 */
void Land::generate(Stepper & stepper)
{
    for (unsigned int y = 0; y < _height; ++y) {
        vector<unique_ptr<Tile> > column;

        for (unsigned int x = 0; x < _width; ++x) {
            column.push_back(make_unique<Tile>(x, y));
            stepper.attach(*(column.back().get()));
        }

        _tiles.push_back(move(column));
    }
}
