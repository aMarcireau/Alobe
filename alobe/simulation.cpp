#include "simulation.h"

/**
 * Constructor
 */
Simulation::Simulation(unique_ptr<Stepper> stepper, unique_ptr<Land> land):
    my_stepper(move(stepper)),
    my_land(move(land)),
    my_beings(vector<shared_ptr<Being> >())
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
    while (my_stepper->getStep() < step) {
        nextStep();
    }
}

/**
 * Calculate the simulation next step
 */
void Simulation::nextStep()
{
    my_stepper->increment();
    nextStepCallback();
}

/**
 * Getter for the stepper
 */
Stepper * Simulation::getStepper() const
{
    return my_stepper.get();
}

/**
 * Getter for the land
 */
Land * Simulation::getLand() const
{
    return my_land.get();
}

/**
 * Called at the end of the nextStep method
 */
void Simulation::nextStepCallback()
{
    std::cout << "Step: "<< my_stepper->getStep() << std::endl;
}
