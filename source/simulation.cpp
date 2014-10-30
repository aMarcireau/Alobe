#include "simulation.h"

/**
 * Constructor
 */
Simulation::Simulation():
    my_stepper(make_unique<Stepper>()),
    my_land(make_unique<Land>(20, 20))
{
    my_stepper->attach(*(my_land.get()));
    my_land->generate(*(this->my_stepper.get()));

    my_population = make_unique<Population>(*(my_land.get()));
    my_stepper->attach(*(my_population.get()));
}

/**
 * Calculate simulation steps until reaching 'step'
 */
void Simulation::toStep(unsigned long step)
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
Stepper * Simulation::getStepper()
{
    return my_stepper.get();
}

/**
 * Getter for the land
 */
Land * Simulation::getLand()
{
    return my_land.get();
}
/**
 * Getter for the population
 */
Population * Simulation::getPopulation()
{
    return my_population.get();
}

/**
 * Called at the end of the nextStep method
 */
void Simulation::nextStepCallback()
{
    my_land->applyChanges();
    my_population->applyChanges();

    std::cout << "Step: "<< my_stepper->getStep() << std::endl;
}
