#ifndef __ALOBE__TILE__
#define __ALOBE__TILE__

#include <iostream>
#include <map>
#include <string>

#include "actor.h"
#include "being.h"

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
        Tile();
        vector<shared_ptr<Being> > getBeings() const;     // Getter for the beings
        unsigned long getBeingsNumber() const;            // Retrieve the number of beings
        void attachBeing(shared_ptr<Being> being);        // Attach a being
        void detachBeing(Being & being);                  // Detach a being
        void applyChanges();                              // Apply changes after a step
        void migrate(map<string, Tile *> neighborsTiles); // Generate the tile beings migration
                                                          // 4 neighboring tiles are expected,
                                                          // with keys 'north', 'south', 'east' and 'west'

    private:
        vector<shared_ptr<Being> > my_beings;
        vector<shared_ptr<Being> > mod_beings;
};

#endif // __ALOBE__TILE__
