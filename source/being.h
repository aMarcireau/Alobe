#ifndef __ALOBE__BEING__
#define __ALOBE__BEING__

#include <string>
#include <map>
#include <memory>
#include <vector>
#include <stdlib.h>

#include "configuration.h"
#include "actor.h"
#include "state.h"
#include "behavior.h"
#include "gender.h"

class Tile;

using namespace std;

/**
 * Being
 * Inherits Actor
 *
 * A being in the simulation
 */
class Being : public Actor
{
    public:
        Being(unique_ptr<Graphics> graphics, string name, map<string, vector<string> > chromosomes);
        string getName() const;                              // Getter for the being name
        map<string, vector<string> > getChromosomes() const; // Getter for the being chromosomes

        bool isDead(); // Is the being dead?
        void kill();   // Kill the being

        State * getState(string stateName);                       // Getter for a state
        bool hasState(string stateName) const;                    // Is the state defined for the being?
        void addState(string stateName, unique_ptr<State> state); // Add a state
        void removeState(string stateName);                       // Remove a state by name

        Behavior * getBehavior(string behaviorName);                          // Getter for a behavior
        bool hasBehavior(string behaviorName) const;                          // Is the behavior defined for the being?
        void addBehavior(string behaviorName, shared_ptr<Behavior> behavior); // Add a behavior
        void removeBehavior(string behaviorName);                             // Remove a behavior by name

        vector<Being *> getParents() const;  // Getter for the being parents
        void addParent(Being & parent);      // Add a parent
        vector<Being *> getChildren() const; // Getter for the being children
        void addChild(Being & child);        // Add a child

        void applyChanges(Stepper & stepper); // Apply changes after a step
        void trace();                         // Trace the being

    private:
        string my_name;
        map<string, vector<string> > my_chromosomes;
        bool my_dead;
        map<string, unique_ptr<State> > my_states;
        map<string, shared_ptr<Behavior> > my_behaviors;
        vector<Being *> my_parents;
        vector<Being *> my_children;
};

#endif // __ALOBE__BEING__
