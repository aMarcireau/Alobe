#include <iostream>
#include <map>
#include <memory>
#include <stdlib.h>

#include <SFML/Graphics.hpp>

#include "simulation.h"
#include "stepper.h"
#include "land.h"
#include "being.h"
#include "gender.h"
#include "normal_law.h"

using namespace std;

int main()
{
    // Set seed for random methods
    // Should be added to proba somehow
    srand(static_cast<unsigned int>(time(NULL)));
    
    // normal law test
    Normal_law norm(5.0, 2.0);
    norm.roll_of_dice(35, 100);

    // Test simulation, stepper, actors
    unique_ptr<Simulation> simulation = make_unique<Simulation>();
    cout
        << "\n"
        << "Created a "
        << simulation->getLand()->getWidth()
        << " by "
        << simulation->getLand()->getHeight()
        << " land. ("
        << simulation->getLand()->getTilesNumber()
        << " tiles)"
    << endl;

    cout << "There are " << simulation->getPopulation()->getBeingsNumber() << " beings" << endl;

    // Print beings positions before simulation
    for (unsigned long x = 0; x < simulation->getLand()->getWidth(); ++x) {
        for (unsigned long y = 0; y < simulation->getLand()->getHeight(); ++y) {

            unsigned long beingsNumber = simulation->getLand()->getTile(x, y)->getBeingsNumber();
            vector<Being *> beings = simulation->getLand()->getTile(x, y)->getBeings();

            unsigned long maleNumber = 0;
            unsigned long femaleNumber = 0;
			unsigned long sickBeingNumber = 0;

            if (beingsNumber > 0) {

                for (
                    vector<Being *>::iterator beingIterator = beings.begin();
                    beingIterator != beings.end();
                    ++beingIterator
                ) {
                    if (dynamic_cast<Gender &>(*((*(beingIterator))->getBehavior("gender"))).get() == "male") {
                        ++maleNumber;
					} 
					if (dynamic_cast<Gender &>(*((*(beingIterator))->getBehavior("gender"))).get() == "female") {
                        ++femaleNumber;
                    }
					if ((*beingIterator)->hasState("alobe") ) {
						++sickBeingNumber;
					}
                }


                cout
                    << "Tile ("
                    << x << ", " << y << "):\n"
                    << "    Males: " << maleNumber << "\n"
					<< "    Females: " << femaleNumber << "\n"
					<< "    Sick beings: " << sickBeingNumber
                << endl;
            }
        }
    }

	simulation->toStep(30);

    // Print beings positions after simulation
    for (unsigned long x = 0; x < simulation->getLand()->getWidth(); ++x) {
        for (unsigned long y = 0; y < simulation->getLand()->getHeight(); ++y) {
            unsigned long beingsNumber = simulation->getLand()->getTile(x, y)->getBeingsNumber();


            if (beingsNumber > 0) {
                string designator = "being";
                if (beingsNumber > 1) {
                    designator = "beings";
                }

                cout
                    << beingsNumber
                    << " "
                    << designator
                    << " on tile ("
                    << x
                    << ", "
                    << y
                    << ")"
                << endl;
            }
        }
    }

	return 0;
}
