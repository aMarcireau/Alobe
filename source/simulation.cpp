#include "simulation.h"

/**
 * Constructor
 */
Simulation::Simulation():
    my_stepper(make_unique<Stepper>()),
    my_land(make_unique<Land>(20, 20))
{
    my_land->generate();
    my_stepper->attach(*getLand());
    my_land->applyChanges(*getStepper());

    my_population = make_unique<Population>(*getLand());
    my_stepper->attach(*getPopulation());
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
 * Getter for the population
 */
Population * Simulation::getPopulation() const
{
    return my_population.get();
}

/**
 * Called at the end of the nextStep method
 */
void Simulation::nextStepCallback()
{
    my_land->applyChanges(*getStepper());
    my_population->applyChanges(*getStepper());

    std::cout << "Step: "<< my_stepper->getStep() << std::endl;
}
