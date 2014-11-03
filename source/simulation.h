#ifndef __ALOBE__SIMULATION__
#define __ALOBE__SIMULATION__

#include <string>
#include <fstream>
#include <time.h>

#include "json11.hpp"

#include "stepper.h"
#include "land.h"
#include "population.h"
#include "migrationEvent.h"

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
        void toStep(unsigned long step);          // Calculate simulation steps until reaching 'step'
        void nextStep();                          // Calculate the simulation next step
        Stepper * getStepper() const;             // Getter for the stepper
        Land * getLand() const;                   // Getter for the land
        Population * getPopulation() const;       // Getter for the population

    private:
        void nextStepCallback();                  // Called at the end of the nextStep method
        void initialize(json11::Json & jsonData); // Initialize the simulation from json data
        json11::Json parseJson(string jsonPath);  // Parse a json file

    private:
        unique_ptr<Stepper> my_stepper;
        unique_ptr<Land> my_land;
        unique_ptr<Population> my_population;
};

#endif // __ALOBE__SIMULATION__
