#ifndef __ALOBE__BEING__
#define __ALOBE__BEING__

#include <string>
#include <map>
#include <memory>
#include <vector>
#include <stdlib.h>

#include "actor.h"
#include "state.h"
#include "behavior.h"

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
        Being(string name, map<string, vector<string> > chromosomes);
        string getName() const;                                       // Getter for the being name
        map<string, vector<string> > getChromosomes() const;	      // Getter for the being chromosomes

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

        vector<Being *> getParents() const; // Getter for the being parents
        void addParent(Being & parent);     // Add a parent

        vector<Being *> getChildren() const; // Getter for the being children
        void addChild(Being & child);        // Add a child

        bool isWillingToMateWith(Being & mate); // Is the being willing to mathe with the given other being?

        void applyChanges(Stepper & stepper); // Apply changes after a step

		//vector<shared_ptr<Chromosome> > setChildChromosomes(Being & mate); // Create a genome for a potential child
		//bool isReadyToMate(Being & mate);                                  // Test if being will mate with an other being
		//vector<shared_ptr<Chromosome> > getBeingHalfChromosomes() const;	 // Getter for half of the genome

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
