#ifndef __ALOBE__SFML_GRAPHICS_WINDOW__
#define __ALOBE__SFML_GRAPHICS_WINDOW__

#include <memory>
#include <SFML/Graphics.hpp>

#include "graphicsWindow.h"

using namespace std;

/**
 * SfmlGraphicsWindow
 * Inherits GraphicsWindow
 *
 * A graphics window wrapper for SFML
 */
class SfmlGraphicsWindow: public GraphicsWindow
{
    public:
        SfmlGraphicsWindow(unsigned long width, unsigned long height);
        sf::RenderWindow * getRenderWindow(); // Getter for the RenderWindow
    private:
        unique_ptr<sf::RenderWindow> my_renderWindow;
};

#endif // __ALOBE__SFML_GRAPHICS_WINDOW__
