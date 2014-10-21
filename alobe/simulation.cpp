#include "simulation.h"

/**
 * Constructor
 */
Simulation::Simulation(unique_ptr<Stepper> stepper, unique_ptr<Land> land):
    _stepper(move(stepper)),
    _land(move(land)),
    _beings(vector<shared_ptr<Being> >())
{
    my_land->generate(*this->my_stepper.get());
    this->my_stepper->attach(*my_land.get());
}

/**
 * Add an actor
 */
void Simulation::add(shared_ptr<Being> being)
{
    my_beings.push_back(being);
    this->my_stepper->attach(*being);
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
 * Getter for the stepper
 */
Stepper * Simulation::getStepper() const
{
    return _stepper.get();
}

/**
 * Getter for the land
 */
Land * Simulation::getLand() const
{
    return _land.get();
}

/**
 * Called at the end of the nextStep method
 */
void Simulation::nextStepCallback()
{
    std::cout << "Step: "<< _stepper->getStep() << std::endl;
}
