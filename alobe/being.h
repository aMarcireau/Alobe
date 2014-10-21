#ifndef __ALOBE__BEING__
#define __ALOBE__BEING__

#include <string>
#include <map>
#include <memory>
#include <vector>

#include "actor.h"
#include "chromosome.h"
#include "tile.h"
#include "state.h"

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
        Being(string name, map< string, shared_ptr<Chromosome> > chromosomes);
        string getName() const;                                                // Getter for the being name
        vector<Being *> getParents() const;                                    // Getter for the being parents
        vector<Being *> getChildren() const;                                   // Getter for the being children
        map<string, shared_ptr<Chromosome> > getChromosomes() const;           // Getter for the being chromosomes
        void addChromosome(shared_ptr<Chromosome> chromsome);                  // Add a chromosome
        void removeChromosome(Chromosome & chromsome);                         // Remove a chromosome by reference
        void removeChromosome(string chromsomeId);                             // Remove a chromosome by id
        void addState(unique_ptr<State> state);                                // Add a state
        void removeState(State & state);                                       // Remove a state by reference
        void removeState(string stateId);                                      // Remove a state by id
        void migrate();                                                        // Generate the being migration
        bool isDead();                                                         // Is the being dead?

    private:
        string my_name;
        map<string, shared_ptr<Chromosome> > my_chromosomes;
        map<string, unique_ptr<State> > my_states;
        vector<Being *> my_parents;
        vector<Being *> my_children;

	//shared_ptr<Being> mate(Being &partner, string name);
};

#endif // __ALOBE__BEING__
