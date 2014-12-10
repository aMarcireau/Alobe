#include "sfmlGraphicsWindow.h"

/**
 * Constructor
 */
SfmlGraphicsWindow::SfmlGraphicsWindow(unsigned long width, unsigned long height):
    GraphicsWindow(width, height),
    my_renderWindow(make_unique<sf::RenderWindow>(sf::VideoMode((unsigned int)width, (unsigned int)height), "Alobe"))
{
}

/**
 * Getter for the RenderWindow
 */
sf::RenderWindow * SfmlGraphicsWindow::getRenderWindow()
{
    return my_renderWindow.get();
}
