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
        vector<Being *> getBeings() const;     // Getter for the beings
        unsigned long getBeingsNumber() const; // Retrieve the number of beings
        void attachBeing(Being & being);       // Attach a being
        void detachBeing(Being & being);       // Detach a being
        void applyChanges(Stepper & stepper);  // Apply changes after a step

    private:
        vector<Being *> my_beings;
        vector<Being *> mod_beings;
};

#endif // __ALOBE__TILE__
