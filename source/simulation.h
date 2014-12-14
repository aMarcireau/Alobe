#ifndef __ALOBE__SIMULATION__
#define __ALOBE__SIMULATION__

#include <string>
#include <memory>
#include <fstream>
#include <time.h>
#include <map>

#include "configuration.h"
#include "sfmlGraphicsWindow.h"
#include "sfmlGraphics.h"
#include "stepper.h"
#include "land.h"
#include "population.h"
#include "beingFactory.h"
#include "migrationEvent.h"
#include "matingEvent.h"
#include "ageEvent.h"
#include "diseaseEvent.h"
#include "exponentialDistribution.h"
#include "constantDistribution.h"
#include "eventManager.h"

using namespace std;

/**
 * Simulation
 *
 * Controller for the simulation
 */
class Simulation
{
    public:
        Simulation();
        void toStep(unsigned long step);                                                         // Calculate simulation steps until reaching 'step'
        void nextStep();                                                                         // Calculate the simulation next step
        Stepper * getStepper() const;                                                            // Getter for the stepper
        Land * getLand() const;                                                                  // Getter for the land
        BeingFactory * getBeingFactory() const;                                                  // Getter for the being factory
        Population * getPopulation() const;                                                      // Getter for the population
        Graphics * getGraphics() const;                                                          // Getter for the graphics
        EventManager * getEventManager() const;                                                  // Getter for the event manager
        void trace();                                                                            // Trace the current step

    private:
        void nextStepCallback();                                                                 // Called at the end of the nextStep method
        void initialize();                                                                       // Initialize the simulation
        shared_ptr<GraphicsWindow> initializeGraphics();                                         // Initialize graphics
        void initializeLand(shared_ptr<GraphicsWindow> sfmlGraphicsWindow);                      // Initialize the land
        void initializePopulation(shared_ptr<GraphicsWindow> sfmlGraphicsWindow);                // Initialize the population
        void initializeSickness();                                                               // Initialize the sickness
        void printInformation(string text, unsigned long textHeight, unsigned long padding = 0); // Print to the information window
        unique_ptr<Graphics> my_graphics;
        unique_ptr<EventManager> my_eventManager;
        unique_ptr<Stepper> my_stepper;
        unique_ptr<Land> my_land;
        unique_ptr<BeingFactory> my_beingFactory;
        unique_ptr<Population> my_population;
        unsigned long printInformationXOffset;
        unsigned long printInformationYOffset;
};

#endif // __ALOBE__SIMULATION__
