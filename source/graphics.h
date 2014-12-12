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
        long long getXSpeed();                          // Getter for the x speed
        long long getYSpeed();                          // Getter for the y speed
        unsigned long getWidth();                       // Getter for the width
        unsigned long getHeight();                      // Getter for the height
        void setWidth(unsigned long width);             // Setter for the width
        void setHeight(unsigned long height);           // Setter for the height
        virtual void drawStripes(
            unsigned long xLeft,
            unsigned long width,
            unsigned long yTop,
            unsigned long height,
            string direction,                           // "horizontal" or "vertical"
            unsigned long spaces,
            unsigned long thickness,
            unsigned long color
        ) = 0;                                          // Draw stripes
        virtual void drawRectangle(
            unsigned long xLeft,
            unsigned long width,
            unsigned long yTop,
            unsigned long height,
            unsigned long color
        ) = 0;                                          // Draw a rectangle
        virtual void drawCircle(
            unsigned long x,
            unsigned long y,
            unsigned long radius,
            unsigned long color
        ) = 0;                                          // Draw a circle
        virtual void drawText(
            unsigned long x,
            unsigned long y,
            string text,
            unsigned long size,
            unsigned long color
        ) = 0;                                          // Draw a text

    private:
        shared_ptr<GraphicsWindow> my_graphicsWindow;
        unsigned long my_xOffset;
        unsigned long my_yOffset;
        long long my_xSpeed;
        long long my_ySpeed;
        unsigned long my_width;
        unsigned long my_height;
};

#endif // __ALOBE__GRAPHICS__
