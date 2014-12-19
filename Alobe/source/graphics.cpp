#include "graphics.h"

/**
 * Constructor
 */
Graphics::Graphics(shared_ptr<GraphicsWindow> graphicsWindow):
    my_graphicsWindow(graphicsWindow),
    my_xOffset(0),
    my_yOffset(0),
    my_width(graphicsWindow->getWidth()),
    my_height(graphicsWindow->getHeight()),
    my_color(0xffffff)
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
    my_xSpeed = (long long)(xOffset) - (long long)(my_xOffset);
    my_xOffset = xOffset;
}

/**
 * Setter for the y offset
 */
void Graphics::setYOffset(unsigned long yOffset)
{
    my_ySpeed = (long long)(yOffset) - (long long)(my_yOffset);
    my_yOffset = yOffset;
}

/**
 * Getter for the x offset
 */
long long Graphics::getXSpeed()
{
    return my_xSpeed;
}

/**
 * Getter for the y offset
 */
long long Graphics::getYSpeed()
{
    return my_ySpeed;
}

/**
 * Getter for the width
 */
unsigned long Graphics::getWidth()
{
    return my_width;
}

/**
 * Getter for the height
 */
unsigned long Graphics::getHeight()
{
    return my_height;
}

/**
 * Setter for the width
 */
void Graphics::setWidth(unsigned long width)
{
    my_width = width;
}

/**
 * Setter for the y offset
 */
void Graphics::setHeight(unsigned long height)
{
    my_height = height;
}

/**
 * Setter for the color
 */
void Graphics::setColor(unsigned long color)
{
    my_color = color;
}

/**
 * Convert hexadecimal color to RGB
 */
vector<unsigned long> Graphics::getRGB()
{
    return {my_color / 0x10000, (my_color / 0x100) % 0x100, my_color % 0x100};
}


/**
 * Calculate the position of an element in a divided interval
 * Interval [minimum, minimum + length] divided by 'total' elements
 */
unsigned long Graphics::intervalToCoordinate(unsigned long minimum, unsigned long length, unsigned long total, unsigned long position) const
{
    if (position > total) {
        throw out_of_range("total");
    }

    return minimum + (unsigned long)((double)(length) / total * position);
}
