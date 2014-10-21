#include <iostream>
#include <map>
#include <memory>

#include "simulation.h"
#include "stepper.h"
#include "land.h"
#include "being.h"

using namespace std;

int main()
{
    unsigned int width, height;

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
        << simulation->getLand()->getWidth()
        << " land. ("
        << simulation->getLand()->getTilesNumber()
        << " tiles):"
    << endl;

    for (unsigned int y = 0; y < simulation->getLand()->getHeight(); ++y) {
        for (unsigned int x = 0; x < simulation->getLand()->getWidth(); ++x) {

            cout << "    " << simulation->getLand()->getTile(x, y)->toString() << endl;
        }
    }

    simulation->randomBeing();
    simulation->randomBeing();
    simulation->randomBeing("Joe");

    cout << "Created beings:" << endl;

    for (
        vector<shared_ptr<Being> >::iterator beingIterator = simulation->getBeings().begin();
        beingIterator != simulation->getBeings().end();
        ++ beingIterator
    ) {
        cout << "    " << (*beingIterator)->getName() << endl;
    }

	simulation->toStep(10);
    
	return 0;
}
