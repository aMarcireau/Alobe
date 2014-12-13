#include "graphicsWindow.h"

/**
 * Constructor
 */
GraphicsWindow::GraphicsWindow(unsigned long width, unsigned long height):
    my_width(width),
    my_height(height)
{
}

/**
 * Getter for the width
 */
unsigned long GraphicsWindow::getWidth()
{
    return my_width;
}

/**
 * Getter for the height
 */
unsigned long GraphicsWindow::getHeight()
{
    return my_height;
}
