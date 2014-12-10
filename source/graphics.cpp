#include "graphics.h"

/**
 * Constructor
 */
Graphics::Graphics(shared_ptr<GraphicsWindow> graphicsWindow):
    my_graphicsWindow(graphicsWindow),
    my_xOffset(0),
    my_yOffset(0)
{
}

/**
 * Pure virtual destructor
 */
Graphics::~Graphics()
{
}

/**
 * Getter for the graphics window
 */
shared_ptr<GraphicsWindow> Graphics::getGraphicsWindow()
{
    return my_graphicsWindow;
}

/**
 * Getter for the x offset
 */
unsigned long Graphics::getXOffset()
{
    return my_xOffset;
}

/**
 * Getter for the y offset
 */
unsigned long Graphics::getYOffset()
{
    return my_yOffset;
}

/**
 * Setter for the x offset
 */
void Graphics::setXOffset(unsigned long xOffset)
{
    my_xOffset = xOffset;
}

/**
 * Setter for the y offset
 */
void Graphics::setYOffset(unsigned long yOffset)
{
    my_yOffset = yOffset;
}
