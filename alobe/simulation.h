#ifndef __ALOBE__SIMULATION__
#define __ALOBE__SIMULATION__

#include <iostream>

#include "stepper.h"
#include "actor.h"

using namespace std;

/**
 * Simulation
 *
 * Controller for the simulation
 */
class Simulation
{
    public:
        Simulation(unique_ptr<Stepper> stepper);
        void add(shared_ptr<Actor> actor);         // Add an actor
        void toStep(unsigned int step);            // Calculate simulation steps until reaching 'step'
        void nextStep();                           // Calculate the simulation next step

    private:
        void nextStepCallback();                   // Called at the end of the nextStep method

    private:
        unique_ptr<Stepper> _stepper;
        vector<shared_ptr<Actor> > _actors;
};

#endif // __ALOBE__SIMULATION__
