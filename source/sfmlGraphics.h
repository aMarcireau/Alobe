#ifndef __ALOBE__SFML_GRAPHICS__
#define __ALOBE__SFML_GRAPHICS__

#include <string>
#include <SFML/Graphics.hpp>

#include "utilities.h"
#include "graphics.h"
#include "sfmlGraphicsWindow.h"

using namespace std;

/**
 * SfmlGraphics
 * Inherits Graphics
 *
 * Implementation of Graphics for SFML
 */
class SfmlGraphics: public Graphics
{
    public:
        SfmlGraphics(shared_ptr<GraphicsWindow> graphicsWindow);
        unique_ptr<Graphics> clone();
        void drawStripes(
            unsigned long xLeft,
            unsigned long xRight,
            unsigned long yTop,
            unsigned long yBottom,
            string direction,                                  // "horizontal" or "vertical"
            unsigned long spacesNumber,
            unsigned long thickness,
            unsigned long color
        );                                                     // Draw stripes
        void drawCircle(
            unsigned long x,
            unsigned long y,
            unsigned long radius,
            unsigned long color
        );                                                     // Draw a circle
    private:
        sf::Color hexadecimalToSfmlColor(unsigned long color); // Hex to SFML color converter
};

#endif // __ALOBE__SFML_GRAPHICS__
