#include "tile.h"

/**
 * Constructor
 */
Tile::Tile(unsigned int x, unsigned int y):
    Actor(),
    my_x(x),
    my_y(y)
{
}

/**
 * X coordinate getter
 */
unsigned int Tile::getX() const
{
	return my_x;
}

/**
 * Y coordinate getter
 */
unsigned int Tile::getY() const
{
	return my_y;
}

/**
 * Get a string of data about the tile
 */
string Tile::toString()
{
	return  "Tile coordinates: " + to_string(my_x) + ", " + to_string(my_y);
};
