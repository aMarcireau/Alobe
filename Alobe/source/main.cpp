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
            } else if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    simulation->getEventManager()->setBeingsColors(
                        event.type == sf::Event::MouseButtonPressed,
                        event.mouseButton.x, event.mouseButton.y,
                        *(simulation->getLand())
                    );
                }
            }
        }
        renderWindow->clear(sf::Color::White);
        simulation->trace();
        renderWindow->display();
    }

    return 0;
}
