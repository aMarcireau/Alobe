#ifndef __ALOBE__TILE__
#define __ALOBE__TILE__

#include <iostream>
#include <map>
#include <string>

#include "actor.h"

using namespace std;

/**
 * Tile
 * Inherits Actor
 *
 * Tile in the simulation
 */
class Tile: public Actor
{
    public:
        Tile(unsigned int x, unsigned int y);
        unsigned int getX() const;            // X coordinate getter
        unsigned int getY() const;            // Y coordinate getter
        string toString();                    // Get a string of data about the tile

    private:
        unsigned int my_x, my_y;
};

#endif // __ALOBE__TILE__
