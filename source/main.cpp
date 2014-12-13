#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "configuration.h"
#include "sfmlGraphics.h"
#include "sfmlGraphicsWindow.h"
#include "simulation.h"

using namespace std;

int main()
{
    unique_ptr<Simulation> simulation = make_unique<Simulation>();

    sf::RenderWindow * renderWindow = (dynamic_cast<SfmlGraphicsWindow &>(*(simulation->getGraphics()->getGraphicsWindow().get()))).getRenderWindow();
    sf::Color backgroundColor = dynamic_cast<SfmlGraphics *>(simulation->getGraphics())->hexadecimalToSfmlColor(BACKGROUND_COLOR);

    renderWindow->setFramerateLimit(FRAMERATE);
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
