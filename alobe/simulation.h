#ifndef __ALOBE__SIMULATION__
#define __ALOBE__SIMULATION__

#include <iostream>

#include "stepper.h"
#include "land.h"
#include "being.h"

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
        void addBeing(shared_ptr<Being> being);                         // Add a being
        void toStep(unsigned int step);                                 // Calculate simulation steps until reaching 'step'
        void nextStep();                                                // Calculate the simulation next step
        Stepper * getStepper() const;                                   // Getter for the stepper
        Land * getLand() const;                                         // Getter for the land

    private:
        void nextStepCallback();                                        // Called at the end of the nextStep method

    private:
        unique_ptr<Stepper> my_stepper;
        unique_ptr<Land> my_land;
        vector<shared_ptr<Being> > my_beings;
};

#endif // __ALOBE__SIMULATION__
