#ifndef __ALOBE__GRAPHICS__
#define __ALOBE__GRAPHICS__

#include <string>
#include <memory>

#include "graphicsWindow.h"

using namespace std;

/**
 * <<Abstract>> Graphics
 *
 * List of graphic commands that should be implemented for a given library
 */
class Graphics
{
    public:
        Graphics(shared_ptr<GraphicsWindow> graphicsWindow);
        virtual ~Graphics() = 0;
        virtual unique_ptr<Graphics> clone() = 0;
        shared_ptr<GraphicsWindow> getGraphicsWindow(); // Getter for the graphics window
        unsigned long getXOffset();                     // Getter for the x offset
        unsigned long getYOffset();                     // Getter for the y offset
        void setXOffset(unsigned long xOffset);         // Setter for the x offset
        void setYOffset(unsigned long yOffset);         // Setter for the y offset
        virtual void drawStripes(
            unsigned long xLeft,
            unsigned long xRight,
            unsigned long yTop,
            unsigned long yBottom,
            string direction,                           // "horizontal" or "vertical"
            unsigned long spaces,
            unsigned long thickness,
            unsigned long color
        ) = 0;                                          // Draw stripes
        virtual void drawCircle(
            unsigned long x,
            unsigned long y,
            unsigned long radius,
            unsigned long color
        ) = 0;                                          // Draw a circle

    private:
        shared_ptr<GraphicsWindow> my_graphicsWindow;
        unsigned long my_xOffset;
        unsigned long my_yOffset;

};

#endif // __ALOBE__GRAPHICS__
