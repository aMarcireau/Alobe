#include "sfmlGraphics.h"

/**
 * Constructor
 */
SfmlGraphics::SfmlGraphics(shared_ptr<GraphicsWindow> graphicsWindow):
    Graphics(graphicsWindow)
{
}

/**
 * Clone
 */
unique_ptr<Graphics> SfmlGraphics::clone()
{
    return make_unique<SfmlGraphics>(getGraphicsWindow());
}

/**
 * Draw stripes
 */
void SfmlGraphics::drawStripes(
    unsigned long xLeft,
    unsigned long xRight,
    unsigned long yTop,
    unsigned long yBottom,
    string direction,
    unsigned long spacesNumber,
    unsigned long thickness,
    unsigned long color
) {
    sf::RenderWindow & renderWindow(dynamic_cast<sf::RenderWindow &>(
        *((dynamic_cast<SfmlGraphicsWindow &>(*(getGraphicsWindow().get()))).getRenderWindow())
    ));

    float width;
    float height;
    if (direction == "horizontal") {
        width = (float)(xRight - xLeft);
        height = (float)(thickness);
    } else if (direction == "vertical") {
        width = (float)(thickness);
        height = (float)(yBottom - yTop);
    } else {
        throw logic_error("Bad key for direction");
    }

    float xPosition;
    float yPosition;
    for (unsigned long lineIndex = 0; lineIndex <= spacesNumber; ++lineIndex) {
        if (direction == "horizontal") {
            xPosition = (float)(xLeft);
            yPosition = (float)intervalToCoordinate(yTop, yBottom, spacesNumber, lineIndex)  - float(thickness) / 2;
        } else if (direction == "vertical") {
            xPosition = (float)intervalToCoordinate(xLeft, xRight, spacesNumber, lineIndex) - (float)(thickness) / 2;
            yPosition = (float)(yTop);
        } else {
            throw logic_error("Bad key for direction");
        }

        sf::RectangleShape line(sf::Vector2f(width, height));
        line.setPosition(xPosition, yPosition);
        line.setFillColor(hexadecimalToSfmlColor(color));
        renderWindow.draw(line);
	}
}

/**
 * Draw a circle
 */
void SfmlGraphics::drawCircle(unsigned long x, unsigned long y, unsigned long radius, unsigned long color)
{
}


/**
 * Hex to SFML color converter
 */
sf::Color SfmlGraphics::hexadecimalToSfmlColor(unsigned long color)
{
    sf::Color sfmlColor(
        color / 0x10000,
        (color / 0x100) % 0x100,
        color % 0x100
    );

    return sfmlColor;
}
