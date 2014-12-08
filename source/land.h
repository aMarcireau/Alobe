#ifndef __ALOBE__LAND__
#define __ALOBE__LAND__

#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "actor.h"
#include "stepper.h"
#include "tile.h"
#include "utilities.h"

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
        Land(shared_ptr<GraphicsWindow> graphicsWindow, unsigned long width, unsigned long height);
        unsigned long getWidth() const;                                // Getter for the land width (number of tiles)
        unsigned long getHeight() const;                               // Getter for the land height (number of tiles)
        Tile * getTile(unsigned long x, unsigned long y) const;        // Get tile by position
        unsigned long getTilesNumber() const;                          // Get the number of tiles
        multimap<unsigned long, Tile *> getNeighboringTilesByDistance(
            unsigned long x,
            unsigned long y,
            unsigned long distance = 1
        ) const;                                                       // Retrieve a tile neighboring tiles by distance
        void applyChanges(Stepper & stepper);                          // Apply changes after a step
        void trace();                                                  // Trace the land

    private:
        unsigned long my_width, my_height;
        vector<vector<unique_ptr<Tile> > > my_tiles;
        vector<vector<unique_ptr<Tile> > > mod_tiles;
};

#endif // __ALOBE__LAND__
