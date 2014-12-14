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
    unsigned long thickness
) {
    sf::RenderWindow * renderWindow = (dynamic_cast<SfmlGraphicsWindow &>(*(getGraphicsWindow().get()))).getRenderWindow();

    float floatWidth;
    float floatHeight;
    if (direction == "horizontal") {
        floatWidth = (float)(width) + thickness / 2.0f;
        floatHeight = (float)(thickness);
    } else if (direction == "vertical") {
        floatWidth = (float)(thickness);
        floatHeight = (float)(height) + thickness / 2.0f;
    } else {
        throw logic_error("Bad key for direction");
    }

    float xPosition;
    float yPosition;
    for (unsigned long lineIndex = 0; lineIndex <= spacesNumber; ++lineIndex) {
        if (direction == "horizontal") {
            xPosition = (float)(xLeft) - thickness / 2.0f;
            yPosition = (float)intervalToCoordinate(yTop, height - 1, spacesNumber, lineIndex) - thickness / 2.0f;
        } else if (direction == "vertical") {
            xPosition = (float)intervalToCoordinate(xLeft, width - 1, spacesNumber, lineIndex) - thickness / 2.0f;
            yPosition = (float)(yTop) - thickness / 2.0f;
        } else {
            throw logic_error("Bad key for direction");
        }

        sf::RectangleShape line(sf::Vector2f(floatWidth, floatHeight));
        line.setPosition(xPosition, yPosition);
        line.setFillColor(getSfmlColor());
        renderWindow->draw(line);
	}
}

/**
 * Draw a rectangle
 */
void SfmlGraphics::drawRectangle(unsigned long xLeft, unsigned long width, unsigned long yTop, unsigned long height)
{
    sf::RenderWindow * renderWindow = (dynamic_cast<SfmlGraphicsWindow &>(*(getGraphicsWindow().get()))).getRenderWindow();

    sf::RectangleShape rectangle(sf::Vector2f((float)(width), (float)(height)));
    rectangle.setPosition((float)(xLeft), (float)(yTop));
    rectangle.setFillColor(getSfmlColor());
    renderWindow->draw(rectangle);
}

/**
 * Draw a circle
 */
void SfmlGraphics::drawCircle(unsigned long x, unsigned long y, unsigned long radius)
{
    sf::RenderWindow * renderWindow = (dynamic_cast<SfmlGraphicsWindow &>(*(getGraphicsWindow().get()))).getRenderWindow();

    sf::CircleShape circle(radius);
    circle.setPosition((float)(x), (float)(y));
    circle.setFillColor(getSfmlColor());
    renderWindow->draw(circle);
}

/**
 * Draw a text
 */
void SfmlGraphics::drawText(unsigned long x, unsigned long y, string text, unsigned long size)
{
    sf::RenderWindow * renderWindow = (dynamic_cast<SfmlGraphicsWindow &>(*(getGraphicsWindow().get()))).getRenderWindow();

    sf::Text sfmlText;
    sfmlText.setFont(my_font);
    sfmlText.setString(text);
    sfmlText.setCharacterSize((unsigned int)size);
    sfmlText.setColor(getSfmlColor());
    sfmlText.setPosition((float)(x), (float)(y));
    renderWindow->draw(sfmlText);
}

/**
 * Hex to SFML color converter
 */
sf::Color SfmlGraphics::getSfmlColor()
{
    vector<unsigned long> rgbColor = getRGB();

    return sf::Color(rgbColor[0], rgbColor[1], rgbColor[2]);
}
