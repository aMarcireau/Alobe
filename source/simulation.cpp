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
    my_eventManager->setBeingsColors(false, 0, 0, *getLand());
}

/**
 * Initialize the simulation from json data
 */
void Simulation::initialize()
{
    shared_ptr<GraphicsWindow> graphicsWindow = initializeGraphics();

    initializeLand(graphicsWindow);
    initializePopulation(graphicsWindow);
    initializeSickness();
}

/**
 * Getter for the render window
 */
Graphics * Simulation::getGraphics() const
{
    return my_graphics.get();
}

/**
 * Getter for the event manager
 */
EventManager * Simulation::getEventManager() const
{
    return my_eventManager.get();
}


/**
 * Trace the current step
 */
void Simulation::trace()
{
    my_land->trace();

    my_graphics->setColor(TEXT_COLOR);
    printInformationXOffset = my_graphics->getXOffset() + TEXT_PADDING;
    printInformationYOffset = my_graphics->getYOffset() + TEXT_PADDING;

    printInformation("Step " + to_string(my_stepper->getStep()), TITLE_TEXT_HEIGHT, 1);
    printInformation("alive beings: " + to_string(my_population->getBeingsNumber()), TEXT_HEIGHT);
    printInformation("dead beings: " + to_string(my_population->getDeadBeingsNumber()), TEXT_HEIGHT);
    printInformation("sick beings: " + to_string(my_population->getSickBeingsNumber()), TEXT_HEIGHT, 2);

    if (my_eventManager->getTargetBeing() == nullptr) {
        printInformation("< Click on a being to display\nits characteristics >", TEXT_HEIGHT, 1);
    } else {
        printInformation(my_eventManager->getTargetBeing()->getName(), TITLE_TEXT_HEIGHT, 1);
        unsigned long age = BEING_MAXIMUM_AGE - my_eventManager->getTargetBeing()->getState("age")->getValue();
        string ageString = to_string(age) + " year" + ((age > 1) ? ("s") : ("")) + " old";
        if (my_eventManager->getTargetBeing()->isDead()) {
            printInformation("dead (at " + ageString + ")", TEXT_HEIGHT, 1);
        } else {
            string state = "alive";
            if (my_eventManager->getTargetBeing()->hasState("sick")) {
                state = "sick";
            } else if (my_eventManager->getTargetBeing()->hasState("cured")) {
                state = "cured";
            }
            printInformation(state, TEXT_HEIGHT);
            printInformation(ageString, TEXT_HEIGHT, 1);
        }
        printInformation("gender: " + (dynamic_cast<Gender *>((my_eventManager->getTargetBeing())->getBehavior("gender")))->get(), TEXT_HEIGHT);
        printInformation("personality: " + (dynamic_cast<Migration *>((my_eventManager->getTargetBeing())->getBehavior("migration")))->getType(), TEXT_HEIGHT, 1);

        printInformation("parents: ", TEXT_HEIGHT);
        if (my_eventManager->getTargetBeing()->hasParents()) {
            vector<Being *> parents = my_eventManager->getTargetBeing()->getParents();
            for (
                vector<Being *>::iterator parentIterator = parents.begin();
                parentIterator != parents.end();
                ++parentIterator
            ) {
                printInformation("    " + (*parentIterator)->getName(), TEXT_HEIGHT);
            }
        } else {
            printInformation("    no one knows where this", TEXT_HEIGHT);
            printInformation("    being comes from", TEXT_HEIGHT);
        }
        printInformation("children: ", TEXT_HEIGHT);
        if (my_eventManager->getTargetBeing()->hasChildren()) {
            vector<Being *> children = my_eventManager->getTargetBeing()->getChildren();
            for (
                vector<Being *>::iterator childIterator = children.begin();
                childIterator != children.end();
                ++childIterator
            ) {
                printInformation("    " + (*childIterator)->getName(), TEXT_HEIGHT);
            }
        } else {
            printInformation("    this being hasn't found", TEXT_HEIGHT);
            printInformation("    love yet", TEXT_HEIGHT);
        }
        printInformation("", 0, 1);
    }

    my_graphics->setColor(GRID_COLOR);
    my_graphics->drawStripes(
        my_graphics->getXOffset(), my_graphics->getWidth(),
        my_graphics->getYOffset(), my_graphics->getHeight(),
        "horizontal",
        1,
        GRID_THICKNESS
    );
    my_graphics->drawStripes(
        my_graphics->getXOffset(), my_graphics->getWidth(),
        my_graphics->getYOffset(), my_graphics->getHeight(),
        "vertical",
        1,
        GRID_THICKNESS
    );
}

/**
 * Initialize graphics
 */
shared_ptr<GraphicsWindow> Simulation::initializeGraphics()
{
    shared_ptr<SfmlGraphicsWindow> graphicsWindow = make_shared<SfmlGraphicsWindow>(WINDOW_WIDTH, WINDOW_HEIGHT);
    my_graphics = make_unique<SfmlGraphics>(graphicsWindow);
    my_eventManager = make_unique<EventManager>();

    my_graphics->setXOffset(INFORMATION_PADDING);
    my_graphics->setYOffset(INFORMATION_PADDING);
    my_graphics->setWidth(INFORMATION_WIDTH);
    my_graphics->setHeight(WINDOW_HEIGHT - 2 * INFORMATION_PADDING);
    printInformationXOffset = 0;
    printInformationYOffset = 0;

    return graphicsWindow;
}

/**
 * Initialize the land
 */
void Simulation::initializeLand(shared_ptr<GraphicsWindow> graphicsWindow)
{
    my_land = make_unique<Land>(make_unique<SfmlGraphics>(graphicsWindow), LAND_WIDTH, LAND_HEIGHT);
    my_land->getGraphics()->setColor(GRID_COLOR);
    my_land->applyChanges(*getStepper());
    my_land->attachEvent(make_shared<MigrationEvent>());
    my_land->getGraphics()->setXOffset(LAND_PADDING + INFORMATION_WIDTH + INFORMATION_PADDING);
    my_land->getGraphics()->setYOffset(LAND_PADDING);
    my_land->getGraphics()->setWidth(my_land->getGraphics()->getWidth() - LAND_PADDING * 2 - INFORMATION_WIDTH - INFORMATION_PADDING);
    my_land->getGraphics()->setHeight(my_land->getGraphics()->getHeight() - LAND_PADDING * 2);
    my_stepper->attach(*getLand());
}

/**
 * Initialize the population
 */
void Simulation::initializePopulation(shared_ptr<GraphicsWindow> graphicsWindow)
{
    my_beingFactory = make_unique<BeingFactory>(make_unique<SfmlGraphics>(graphicsWindow));
    my_population = make_unique<Population>(make_unique<SfmlGraphics>(graphicsWindow), *getLand(), *getBeingFactory());
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
    my_stepper->attach(*getPopulation());
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
            (*sickBeingIterator)->addState("sick", make_unique<State>(DISEASE_ALWAYS_DEAD));
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
    my_eventManager->setBeingsColors(false, 0, 0, *getLand());
}

/**
 * Print to the information window
 */
void Simulation::printInformation(string text, unsigned long textHeight, unsigned long padding)
{
    my_graphics->drawText(printInformationXOffset, printInformationYOffset, text, textHeight);
    printInformationYOffset += (textHeight + TEXT_PADDING * padding);
}
