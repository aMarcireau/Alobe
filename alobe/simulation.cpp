#include "simulation.h"

/**
 * Constructor
 */
Simulation::Simulation(unique_ptr<Stepper> stepper, unique_ptr<Land> land):
    my_stepper(move(stepper)),
    my_land(move(land)),
    my_beings(vector<shared_ptr<Being> >())
{
    srand(static_cast<unsigned int>(time(NULL)));

    my_land->generate(*this->my_stepper.get());
    this->my_stepper->attach(*my_land.get());
}

/**
 * Add a being
 */
void Simulation::addBeing(shared_ptr<Being> being, unsigned int x, unsigned int y)
{
    my_beings.push_back(being);
    this->my_stepper->attach(*being);
}

/**
 * Generate a random being
 */
void Simulation::randomBeing(string name)
{
    if (name == "") {
        name = to_string(rand());
    }
    shared_ptr<Being> being(make_shared<Being>(name, map<string, shared_ptr<Chromosome> >()));
    being->addState(make_unique<State>("life"));

    this->addBeing(being, rand() % this->my_land->getWidth(), rand() % this->my_land->getHeight());
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

vector<shared_ptr<Being> > Simulation::getBeings() const
{
    return my_beings;
}

/**
 * Called at the end of the nextStep method
 */
void Simulation::nextStepCallback()
{
    std::cout << "Step: "<< my_stepper->getStep() << std::endl;
}
