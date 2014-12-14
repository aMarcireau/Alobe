#ifndef __ALOBE__EVENT_MANAGER__
#define __ALOBE__EVENT_MANAGER__

#include <vector>
#include "land.h"
#include "tile.h"
#include "being.h"
#include "configuration.h"

/**
 * EventManager
 *
 * Manages the window events
 */
class EventManager
{
    public:
        EventManager();
        void setBeingsColors(
            bool isMouseClicked,
            unsigned long xMousePosition,
            unsigned long yMousePosition,
            Land & land
        );                                // Set the color of each being
        Being * getTargetBeing();         // Getter fot the target being

    private:
        Being * my_targetBeing;
};

#endif // __EVENT_MANAGER__
