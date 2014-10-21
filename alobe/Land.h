#ifndef __ALOBE__LAND__
#define __ALOBE__LAND__

#include <iostream>
#include <vector>
#include <memory>

#include "actor.h"
#include "tile.h"

using namespace std;

/**
 * Land
 * Inherits Actor
 *
 * Land of the simulation
 */
class Land: Actor
{
    public:
        Land(unsigned int width, unsigned int height);
        unsigned int getWidth() const;                        // Getter for the land width (number of tiles)
        unsigned int getHeight() const;                       // Getter for the land height (number of tiles)
        Tile * getTile(unsigned int x, unsigned int y) const; // Get tile by position
        unsigned int getTilesNumber() const;                  // Get the number of tiles
        void generate(Stepper & stepper);                     // Generate the land tiles


    private:
        unsigned int _width, _height;
        vector<vector<unique_ptr<Tile> > > _tiles;
};

#endif // __ALOBE__LAND__
