#ifndef __ALOBE__LAND__
#define __ALOBE__LAND__

#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "actor.h"
#include "tile.h"
#include "stepper.h"

using namespace std;

/**
 * Land
 * Inherits Actor
 *
 * Land of the simulation
 */
class Land: public Actor
{
    public:
        Land(unsigned long width, unsigned long height);
        unsigned long getWidth() const;                                               // Getter for the land width (number of tiles)
        unsigned long getHeight() const;                                              // Getter for the land height (number of tiles)
        Tile * getTile(unsigned long x, unsigned long y) const;                       // Get tile by position
        unsigned long getTilesNumber() const;                                         // Get the number of tiles
        void generate(Stepper & stepper);                                             // Generate the land tiles
        void migrate();                                                               // Generate the land beings migration
        map<string, Tile *> getTileNeighbors(unsigned long x, unsigned long y) const; // Retrieve a tile neighboring tiles
        void applyChanges();                                                          // Apply changes after a step

    private:
        unsigned long my_width, my_height;
        vector<vector<unique_ptr<Tile> > > my_tiles;
};

#endif // __ALOBE__LAND__
