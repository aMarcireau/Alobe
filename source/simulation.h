#ifndef __ALOBE__SIMULATION__
#define __ALOBE__SIMULATION__

#include <string>
#include <memory>
#include <fstream>
#include <time.h>

#include "stepper.h"
#include "land.h"
#include "population.h"
#include "beingFactory.h"
#include "migrationEvent.h"
#include "matingEvent.h"

using namespace std;

/**
 * Simulation
 *
 * Controller for the simulation
 */
class Simulation
{
    public:
        Simulation(string jsonPath);
        void toStep(unsigned long step);         // Calculate simulation steps until reaching 'step'
        void nextStep();                         // Calculate the simulation next step
        Stepper * getStepper() const;            // Getter for the stepper
        Land * getLand() const;                  // Getter for the land
        BeingFactory * getBeingFactory() const;  // Getter for the being factory
        Population * getPopulation() const;      // Getter for the population

    private:
        void nextStepCallback();                 // Called at the end of the nextStep method
        void initialize();                       // Initialize the simulation

    private:
        unique_ptr<Stepper> my_stepper;
        unique_ptr<Land> my_land;
        unique_ptr<BeingFactory> my_beingFactory;
        unique_ptr<Population> my_population;
};

#endif // __ALOBE__SIMULATION__
