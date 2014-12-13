#include "sfmlGraphics.h"

/**
 * Constructor
 */
SfmlGraphics::SfmlGraphics(shared_ptr<GraphicsWindow> graphicsWindow):
    Graphics(graphicsWindow),
    my_font(sf::Font())
{
    my_font.loadFromFile(FONT_PATH);
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
    unsigned long width,
    unsigned long yTop,
    unsigned long height,
    string direction,
    unsigned long spacesNumber,
    unsigned long thickness,
    unsigned long color
) {
    sf::RenderWindow * renderWindow = (dynamic_cast<SfmlGraphicsWindow &>(*(getGraphicsWindow().get()))).getRenderWindow();

    float floatWidth;
    float floatHeight;
    if (direction == "horizontal") {
        floatWidth = (float)(width);
        floatHeight = (float)(thickness);
    } else if (direction == "vertical") {
        floatWidth = (float)(thickness);
        floatHeight = (float)(height);
    } else {
        throw logic_error("Bad key for direction");
    }

    float xPosition;
    float yPosition;
    for (unsigned long lineIndex = 0; lineIndex <= spacesNumber; ++lineIndex) {
        if (direction == "horizontal") {
            xPosition = (float)(xLeft);
            yPosition = (float)intervalToCoordinate(yTop, width - 1, spacesNumber, lineIndex)  - float(thickness) / 2;
        } else if (direction == "vertical") {
            xPosition = (float)intervalToCoordinate(xLeft, height - 1, spacesNumber, lineIndex) - (float)(thickness) / 2;
            yPosition = (float)(yTop);
        } else {
            throw logic_error("Bad key for direction");
        }

        sf::RectangleShape line(sf::Vector2f(floatWidth, floatHeight));
        line.setPosition(xPosition, yPosition);
        line.setFillColor(hexadecimalToSfmlColor(color));
        renderWindow->draw(line);
	}
}

/**
 * Draw a rectangle
 */
void SfmlGraphics::drawRectangle(unsigned long xLeft, unsigned long width, unsigned long yTop, unsigned long height, unsigned long color)
{
    sf::RenderWindow * renderWindow = (dynamic_cast<SfmlGraphicsWindow &>(*(getGraphicsWindow().get()))).getRenderWindow();

    sf::RectangleShape rectangle(sf::Vector2f((float)(width), (float)(height)));
    rectangle.setPosition((float)(xLeft), (float)(yTop));
    rectangle.setFillColor(hexadecimalToSfmlColor(color));
    renderWindow->draw(rectangle);
}

/**
 * Draw a circle
 */
void SfmlGraphics::drawCircle(unsigned long x, unsigned long y, unsigned long radius, unsigned long color)
{
    sf::RenderWindow * renderWindow = (dynamic_cast<SfmlGraphicsWindow &>(*(getGraphicsWindow().get()))).getRenderWindow();

    sf::CircleShape circle(radius);
    circle.setPosition((float)(x), (float)(y));
    circle.setFillColor(hexadecimalToSfmlColor(color));
    renderWindow->draw(circle);
}

/**
 * Draw a text
 */
void SfmlGraphics::drawText(unsigned long x, unsigned long y, string text, unsigned long size, unsigned long color)
{
    sf::RenderWindow * renderWindow = (dynamic_cast<SfmlGraphicsWindow &>(*(getGraphicsWindow().get()))).getRenderWindow();

    sf::Text sfmlText;
    sfmlText.setFont(my_font);
    sfmlText.setString(text);
    sfmlText.setCharacterSize((unsigned int)size);
    sfmlText.setColor(hexadecimalToSfmlColor(color));
    sfmlText.setPosition((float)(x), (float)(y));
    renderWindow->draw(sfmlText);
}

/**
 * Hex to SFML color converter
 */
sf::Color SfmlGraphics::hexadecimalToSfmlColor(unsigned long color)
{
    vector<unsigned long> rgbColor = hexadecimalToRGB(color);

    return sf::Color(rgbColor[0], rgbColor[1], rgbColor[2]);
}
