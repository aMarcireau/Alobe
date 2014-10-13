#include "simulation.h"

/**
 * Constructor
 */
Simulation::Simulation(unique_ptr<Stepper> stepper):
    _stepper(move(stepper)),
    _actors(vector<shared_ptr<Actor> >())
{
}

/**
 * Add an actor
 */
void Simulation::add(shared_ptr<Actor> actor)
{
    _actors.push_back(actor);
}

/**
 * Calculate simulation steps until reaching 'step'
 */
void Simulation::toStep(unsigned int step)
{
    while (_stepper->getStep() < step) {
        nextStep();
    }
}

/**
 * Calculate the simulation next step
 */
void Simulation::nextStep()
{
    _stepper->increment();
    nextStepCallback();
}

/**
 * Called at the end of the nextStep method
 */
void Simulation::nextStepCallback()
{
    std::cout << "Step: "<< _stepper->getStep() << std::endl;
}
