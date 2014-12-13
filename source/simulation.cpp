#include "simulation.h"

/**
 * Constructor
 */
Simulation::Simulation():
    my_stepper(make_unique<Stepper>())
{
    srand((unsigned int)(time(NULL)));
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
}

/**
 * Initialize the simulation from json data
 */
void Simulation::initialize()
{
    shared_ptr<SfmlGraphicsWindow> sfmlGraphicsWindow = make_shared<SfmlGraphicsWindow>(WINDOW_WIDTH, WINDOW_HEIGHT);
    my_graphics = make_unique<SfmlGraphics>(sfmlGraphicsWindow);

    initializeLand(sfmlGraphicsWindow);
    initializePopulation(sfmlGraphicsWindow);
    initializeSickness();

    my_stepper->attach(*getLand());
    my_stepper->attach(*getPopulation());
}

/**
 * Getter for the render window
 */
Graphics * Simulation::getGraphics() const
{
    return my_graphics.get();
}

/**
 * Trace the current step
 */
void Simulation::trace()
{
    my_land->trace();
    my_graphics->drawText(
        LAND_PADDING, TITLE_PADDING,
        "Step: " + to_string(my_stepper->getStep()),
        LAND_PADDING - TITLE_PADDING * 2 - GRID_THICKNESS / 2,
        TITLE_COLOR
    );

    my_graphics->drawText(
        LAND_PADDING, TITLE_PADDING + WINDOW_HEIGHT - LAND_PADDING,
        "Alive beings: " + to_string(my_population->getBeingsNumber()) +
        "    Dead Beings: " + to_string(my_population->getDeadBeingsNumber()) +
        "    Sick beings: " + to_string(my_population->getSickBeingsNumber()),
        LAND_PADDING - TITLE_PADDING * 2 - GRID_THICKNESS / 2,
        TITLE_COLOR
    );
}

/**
 * Initialize the land
 */
void Simulation::initializeLand(shared_ptr<SfmlGraphicsWindow> sfmlGraphicsWindow)
{
    my_land = make_unique<Land>(make_unique<SfmlGraphics>(sfmlGraphicsWindow), LAND_WIDTH, LAND_HEIGHT);
    my_land->applyChanges(*getStepper());
    my_land->attachEvent(make_shared<MigrationEvent>());
    my_land->getGraphics()->setXOffset(LAND_PADDING);
    my_land->getGraphics()->setYOffset(LAND_PADDING);
    my_land->getGraphics()->setWidth(my_land->getGraphics()->getWidth() - LAND_PADDING * 2);
    my_land->getGraphics()->setHeight(my_land->getGraphics()->getHeight() - LAND_PADDING * 2);
}

/**
 * Initialize the population
 */
void Simulation::initializePopulation(shared_ptr<SfmlGraphicsWindow> sfmlGraphicsWindow)
{
    my_beingFactory = make_unique<BeingFactory>(make_unique<SfmlGraphics>(sfmlGraphicsWindow));
    my_population = make_unique<Population>(make_unique<SfmlGraphics>(sfmlGraphicsWindow), *getLand(), *getBeingFactory());
    for (
        unsigned long beingsIndex = 0;
        beingsIndex < (unsigned long)(LAND_WIDTH * LAND_HEIGHT * INITIAL_MEDIAN_DENSITY);
        ++beingsIndex
    ) {
        my_population->addBeing();
    }
	my_population->attachEvent(make_shared<MatingEvent>(make_unique<ConstantDistribution>(BEING_MATE_RATIO)));
    my_population->attachEvent(make_shared<AgeEvent>(make_unique<ExponentialDistribution>(BEING_MAXIMUM_AGE, 0)));
    my_population->applyChanges(*getStepper());
    my_land->applyChanges(*getStepper());
}

/**
 * Initialize the sickness
 */
void Simulation::initializeSickness()
{
    multimap<unsigned long, Tile *> targetTiles = my_land->getNeighboringTilesByDistance(
        (unsigned long)(LAND_WIDTH / 2),
        (unsigned long)(LAND_HEIGHT / 2),
        DISEASE_INITIAL_RADIUS
    );
    
    for (
        map<unsigned long, Tile *>::iterator tilesByDistanceIterator = targetTiles.begin();
        tilesByDistanceIterator != targetTiles.end();
        ++tilesByDistanceIterator
    ) {
        vector<Being *> sickBeings = tilesByDistanceIterator->second->getBeings();

        for (
            vector<Being *>::iterator sickBeingIterator = sickBeings.begin();
            sickBeingIterator != sickBeings.end();
            ++sickBeingIterator
        ) {
            (*sickBeingIterator)->addState("alobe", make_unique<State>(DISEASE_ALWAYS_DEAD));
        }
    }
    for (unsigned long x = 0; x < my_land->getWidth(); ++x) {
		for (unsigned long y = 0; y < my_land->getHeight(); ++y) {
			my_land->getTile(x, y)->attachEvent(make_shared<DiseaseEvent>(
                make_unique<ConstantDistribution>(DISEASE_TRANSMISSION),
                make_unique<ConstantDistribution>(DISEASE_REMISSION),
                make_unique<ExponentialDistribution>(DISEASE_ALWAYS_DEAD, 0)
            ));
		}
	}
}
