#ifndef __ALOBE__SIMULATION__
#define __ALOBE__SIMULATION__

#include <iostream>

#include "stepper.h"
#include "land.h"

class Being; // Pre-declared Bing. TODO: replace with #include "being.h" when created

using namespace std;

/**
 * Simulation
 *
 * Controller for the simulation
 */
class Simulation
{
    public:
        Simulation(unique_ptr<Stepper> stepper, unique_ptr<Land> land);
        void add(shared_ptr<Being> being);                              // Add a being
        void toStep(unsigned int step);                                 // Calculate simulation steps until reaching 'step'
        void nextStep();                                                // Calculate the simulation next step
        Stepper * getStepper() const;                                   // Getter for the stepper
        Land * getLand() const;                                         // Getter for the land

    private:
        void nextStepCallback();                                        // Called at the end of the nextStep method

    private:
        unique_ptr<Stepper> _stepper;
        unique_ptr<Land> _land;
        vector<shared_ptr<Being> > _beings;
};

#endif // __ALOBE__SIMULATION__
