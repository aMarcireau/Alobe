#ifndef __ALOBE__SIMULATION__
#define __ALOBE__SIMULATION__

#include <string>
#include <time.h>

#include "stepper.h"
#include "land.h"
#include "population.h"

using namespace std;

/**
 * Simulation
 *
 * Controller for the simulation
 */
class Simulation
{
    public:
        Simulation();
        void toStep(unsigned long step);      // Calculate simulation steps until reaching 'step'
        void nextStep();                      // Calculate the simulation next step
        Stepper * getStepper();               // Getter for the stepper
        Land * getLand();                     // Getter for the land
        Population * getPopulation();         // Getter for the population

    private:
        void nextStepCallback();              // Called at the end of the nextStep method

    private:
        unique_ptr<Stepper> my_stepper;
        unique_ptr<Land> my_land;
        unique_ptr<Population> my_population;
};

#endif // __ALOBE__SIMULATION__
