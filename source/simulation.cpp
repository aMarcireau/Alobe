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

    cout << "\n" << "Step "<< my_stepper->getStep() << "\n"
        << "    Alive beings: " << my_population->getBeingsNumber() << "\n"
        << "    Dead beings: " << my_population->getDeadBeingsNumber() << "\n"
		<< "    Sick beings: " << my_population->getSickBeingsNumber() << "\n"
        << std::endl;
}

/**
 * Initialize the simulation from json data
 */
void Simulation::initialize()
{
    my_land = make_unique<Land>(5, 5);
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
    my_population->attachEvent(make_shared<AgeEvent>());

	for (unsigned long x = 0; x < my_land->getWidth(); ++x) {
		for (unsigned long y = 0; y < my_land->getHeight(); ++y) {
			my_land->getTile(x, y)->attachEvent(make_shared<DiseaseEvent>());
		}
	}
    my_population->applyChanges(*getStepper());

    my_land->applyChanges(*getStepper()); // Apply changes in order to place the beings on the tiles

    my_stepper->attach(*getLand());
    my_stepper->attach(*getPopulation());
}



