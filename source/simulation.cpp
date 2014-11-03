#include "simulation.h"

/**
 * Constructor
 */
Simulation::Simulation(string jsonPath):
    my_stepper(make_unique<Stepper>())
{
    json11::Json jsonData = parseJson(jsonPath);
    initialize(jsonData);
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

/**
 * Initialize the simulation from json data
 */
void Simulation::initialize(json11::Json & jsonData)
{
    my_land = make_unique<Land>(
        static_cast<unsigned int>(jsonData["land"]["width"].number_value()),
        static_cast<unsigned int>(jsonData["land"]["height"].number_value())
    );
    my_land->applyChanges(*getStepper()); // Apply changes in order to generate the tiles
    my_land->attachEvent(make_shared<MigrationEvent>());

    my_population = make_unique<Population>(*getLand());
    for (
        unsigned long beingsIndex = 0;
        beingsIndex < jsonData["beings"]["number"].number_value();
        ++beingsIndex
    ) {
        my_population->randomBeing();
    }
    my_population->applyChanges(*getStepper());
    my_land->applyChanges(*getStepper()); // Apply changes in order to place the beings on the tiles

    my_stepper->attach(*getLand());
    my_stepper->attach(*getPopulation());
}

/**
 * Parse a json file
 */
json11::Json Simulation::parseJson(string jsonPath)
{
    json11::Json jsonData;
    string parseError = "";

    ifstream ifs(jsonPath);
    string jsonContent(
        (istreambuf_iterator<char>(ifs)),
        (istreambuf_iterator<char>())
    );

    jsonData = jsonData.parse(jsonContent, parseError);

    if (parseError != "") {
        throw runtime_error("Error occurred while parsing json: " + parseError);
    }

    return jsonData;
}
