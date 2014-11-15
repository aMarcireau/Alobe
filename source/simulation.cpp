#include "simulation.h"

/**
 * Constructor
 */
Simulation::Simulation():
    my_stepper(make_unique<Stepper>())
{
    initialize();
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
 * Getter for the being factory
 */
BeingFactory * Simulation::getBeingFactory() const
{
    return my_beingFactory.get();
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

    std::cout << "\n" << "Step "<< my_stepper->getStep() << std::endl;
	std::cout << "There are " << my_population->getBeingsNumber() << " beings" << std::endl;
}

/**
 * Initialize the simulation from json data
 */
void Simulation::initialize()
{
    my_land = make_unique<Land>(6, 6);
    my_land->applyChanges(*getStepper()); // Apply changes in order to generate the tiles
    my_land->attachEvent(make_shared<MigrationEvent>());

    my_beingFactory = make_unique<BeingFactory>();

    my_population = make_unique<Population>(*getLand(), *getBeingFactory());
    for (
        unsigned long beingsIndex = 0;
        beingsIndex < 20;
        ++beingsIndex
    ) {
        my_population->addBeing();
    }
	my_population->attachEvent(make_shared<MatingEvent>());
    my_population->applyChanges(*getStepper());

    my_land->applyChanges(*getStepper()); // Apply changes in order to place the beings on the tiles

    my_stepper->attach(*getLand());
    my_stepper->attach(*getPopulation());
}
