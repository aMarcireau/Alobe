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
    
    unsigned long width, height;

    cout << "Enter a height for your land: " << endl;
	cin >> height;
	cout << "Enter a width for your land: " << endl;
	cin >> width;

    unique_ptr<Simulation> simulation = make_unique<Simulation>(
        make_unique<Stepper>(),
        make_unique<Land>(width, height)
    );

    cout
        << "Created a "
        << simulation->getLand()->getWidth()
        << " by "
        << simulation->getLand()->getHeight()
        << " land. ("
        << simulation->getLand()->getTilesNumber()
        << " tiles)"
    << endl;

    simulation->randomBeing();
    simulation->randomBeing();
    simulation->randomBeing("Joe");

    cout << "Created beings:" << endl;
	vector<shared_ptr<Being> > beings = simulation->getBeings();
    for (
        vector<shared_ptr<Being> >::iterator beingIterator = beings.begin();
        beingIterator != beings.end();
        ++beingIterator
    ) {
       cout << "    " << (*beingIterator)->getName() << endl;
    }

	simulation->toStep(10);
    
	return 0;
}
