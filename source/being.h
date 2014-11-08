#ifndef __ALOBE__BEING__
#define __ALOBE__BEING__

#include <string>
#include <map>
#include <memory>
#include <vector>
#include <stdlib.h>

#include "actor.h"
#include "chromosome.h"
#include "state.h"

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
        Being(string name, vector<shared_ptr<Chromosome> > chromosomes);
        string getName() const;                                          // Getter for the being name
        vector< shared_ptr<Chromosome> > getChromosomes() const;	     // Getter for the being chromosomes

        bool isDead(); // Is the being dead?
        void kill();   // Kill the being

        State * getState(string stateName);                       // Getter for a state
        bool hasState(string stateName) const;                    // Is the state defined for the being?
        void addState(string stateName, unique_ptr<State> state); // Add a state
        void removeState(string stateName);                       // Remove a state by id

        vector<Being *> getParents() const; // Getter for the being parents
        void addParent(Being & parent);     // Add a parent

        vector<Being *> getChildren() const; // Getter for the being children
        void addChild(Being & child);        // Add a child

        bool isWillingToMateWith(Being & mate); // Is the being willing to mathe with the given other being?

        void applyChanges(Stepper & stepper); // Apply changes after a step

        virtual Tile * getMigration(
            multimap<unsigned long, Tile *> & neighboringTilesBydistance
        ) = 0;                                                           // Get the tile where the being is willing to migrate

        virtual string getGender() = 0;                                  // Get the being gender

		//vector<shared_ptr<Chromosome> > setChildChromosomes(Being & mate); // Create a genome for a potential child
		//bool isReadyToMate(Being & mate);                                  // Test if being will mate with an other being
		//vector<shared_ptr<Chromosome> > getBeingHalfChromosomes() const;	 // Getter for half of the genome

    private:
        string my_name;
        vector<shared_ptr<Chromosome> > my_chromosomes;
        bool my_dead;
        map<string, unique_ptr<State> > my_states;
        vector<Being *> my_parents;
        vector<Being *> my_children;
};

#endif // __ALOBE__BEING__
