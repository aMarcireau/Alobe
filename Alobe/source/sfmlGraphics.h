#ifndef __ALOBE__SFML_GRAPHICS__
#define __ALOBE__SFML_GRAPHICS__

#include <string>
#include <SFML/Graphics.hpp>

#include "configuration.h"
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
            unsigned long width,
            unsigned long yTop,
            unsigned long height,
            string direction,           // "horizontal" or "vertical"
            unsigned long spacesNumber,
            unsigned long thicknes
        );                              // Draw stripes
        void drawRectangle(
            unsigned long xLeft,
            unsigned long width,
            unsigned long yTop,
            unsigned long height
        );                              // Draw a rectangle
        void drawCircle(
            unsigned long x,
            unsigned long y,
            unsigned long radius
        );                              // Draw a circle
        void drawText(
            unsigned long x,
            unsigned long y,
            string text,
            unsigned long size
        );                              // Draw a text
        sf::Color getSfmlColor();       // Getter for the color in SFML format
    private:
        sf::Font my_font;
};

#endif // __ALOBE__SFML_GRAPHICS__
