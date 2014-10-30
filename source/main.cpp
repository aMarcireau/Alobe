#include <iostream>
#include <map>
#include <memory>

#include "simulation.h"
#include "stepper.h"
#include "land.h"
#include "being.h"
#include "normal_law.h"

using namespace std;

int main()
{
    
    // normal law test
    Normal_law norm(5.0, 2.0);
    norm.sample(1000);
    cout << norm.map_to_string();

    // Test simulation, stepper, actors
    unique_ptr<Simulation> simulation = make_unique<Simulation>();
    cout
        << "Created a "
        << simulation->getLand()->getWidth()
        << " by "
        << simulation->getLand()->getHeight()
        << " land. ("
        << simulation->getLand()->getTilesNumber()
        << " tiles)"
    << endl;

    simulation->getPopulation()->randomBeing(*(simulation->getStepper()));
    simulation->getPopulation()->randomBeing(*(simulation->getStepper()));
    simulation->getPopulation()->randomBeing(*(simulation->getStepper()));
    simulation->getPopulation()->randomBeing(*(simulation->getStepper()));

	simulation->toStep(10);
    
	return 0;
}
