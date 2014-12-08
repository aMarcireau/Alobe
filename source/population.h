#ifndef __ALOBE__POPULATION__
#define __ALOBE__POPULATION__

#include <memory>
#include <vector>
#include <stdlib.h>

#include "actor.h"
#include "stepper.h"
#include "being.h"
#include "land.h"
#include "beingFactory.h"

using namespace std;

/**
 * Population
 * Inherits Actor
 *
 * A population of beings
 */
class Population : public Actor
{
    public:
        Population(shared_ptr<GraphicsWindow> graphicsWindow, Land & land, BeingFactory & beingFactory);
		Land * getLand() const;                               // Getter for the land
        BeingFactory * getBeingFactory() const;               // Getter for the being factory
        vector<Being *> getBeings();                          // Getter for the beings
		unsigned long getBeingsNumber() const;                // Get the number of beings
        unsigned long getDeadBeingsNumber() const;            // Get the number of dead beings
		unsigned long getSickBeingsNumber();                  // Get the number of sick beings
        void addBeing();                                      // Generate a random being
        void addBeing(
            unique_ptr<Being> being,
            unsigned long x,
            unsigned long y
        );                                                    // Add a being
        void applyChanges(Stepper & stepper);                 // Apply changes after a step
        void trace();                                         // Trace the population

    private:
        Land * my_land;
        BeingFactory * my_beingFactory;
        vector<unique_ptr<Being> > my_beings;
        vector<unique_ptr<Being> > mod_beings;
        vector<unique_ptr<Being> > dead_beings;
};

#endif //__ALOBE__POPULATION__
