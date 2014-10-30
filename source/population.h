#ifndef __ALOBE__POPULATION__
#define __ALOBE__POPULATION__

#include <memory>
#include <vector>

#include "actor.h"
#include "stepper.h"
#include "being.h"
#include "land.h"

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
        Population(Land & land);
        void addBeing(
            unique_ptr<Being> being,
            unsigned long x,
            unsigned long y,
            Stepper & stepper
        );                                   // Add a being
        void randomBeing(Stepper & stepper); // Generate a random being
        void applyChanges();                 // Apply changes after a step

    private:
        Land * my_land;
        vector<unique_ptr<Being> > my_beings;
};

#endif //__ALOBE__POPULATION__
