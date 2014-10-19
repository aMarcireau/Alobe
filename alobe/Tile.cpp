#include "tile.h"

/**
 * Constructor
 */
Tile::Tile(unsigned int x, unsigned int y):
    Actor(),
    _x(x),
    _y(y)
{
}

/**
 * X coordinate getter
 */
unsigned int Tile::getX() const
{
	return _x;
}

/**
 * Y coordinate getter
 */
unsigned int Tile::getY() const
{
	return _y;
}

/**
 * Get a string of data about the tile
 */
string Tile::toString()
{
	return  "Tile coordinates: " + to_string(_x) + ", " + to_string(_y);
};
