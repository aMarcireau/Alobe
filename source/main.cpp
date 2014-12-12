#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "configuration.h"
#include "utilities.h"
#include "sfmlGraphicsWindow.h"
#include "simulation.h"

using namespace std;

int main()
{
    // Set seed for random methods
    // Should be added to proba somehow
    srand(static_cast<unsigned int>(time(NULL)));

    unique_ptr<Simulation> simulation = make_unique<Simulation>();

    sf::RenderWindow * renderWindow = (dynamic_cast<SfmlGraphicsWindow &>(*(simulation->getRenderWindow()->getGraphicsWindow()))).getRenderWindow();
    renderWindow->setFramerateLimit(FRAMERATE);
    vector<unsigned long> rgbBackgroundColor = hexadecimalToRGB(BACKGROUND_COLOR);
    sf::Color backgroundColor(rgbBackgroundColor[0], rgbBackgroundColor[1], rgbBackgroundColor[2]);
    while (renderWindow->isOpen())
	{
        sf::Event event;
		while (renderWindow->pollEvent(event))
		{
            if (event.type == sf::Event::Closed) {
                renderWindow->close();
            } else if (event.type == sf::Event::KeyPressed) {
                 if (event.key.code == sf::Keyboard::Return) {
                    simulation->nextStep();
                }
            }
		}
        renderWindow->clear(backgroundColor);
        simulation->trace();
        renderWindow->display();
    }

    return 0;
}



/*
void test()
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
    simulation->trace();

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
}

*/
