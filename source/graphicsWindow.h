#ifndef __ALOBE__GRAPHICS_WINDOW__
#define __ALOBE__GRAPHICS_WINDOW__

/**
 * <<Abstract>> GraphicsWindow
 *
 * A graphics window wrapper
 */
class GraphicsWindow
{
    public:
        GraphicsWindow(unsigned long width, unsigned long height);
        virtual ~GraphicsWindow() = 0;
        unsigned long getWidth();      // Getter for the width
        unsigned long getHeight();     // Getter for the height
    private:
        unsigned long my_width;
        unsigned long my_height;
};

#endif // __ALOBE__GRAPHICS_WINDOW__
