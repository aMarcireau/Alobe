#ifndef __ALOBE__BEING__
#define __ALOBE__BEING__

#include <string>
#include <map>
#include <memory>
#include <vector>

#include "actor.h"
#include "Chromosome.h"
#include "Tile.h"

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
        void addChromosome(shared_ptr<Chromosome> newChromsome);               // Add a chromosome
        void removeChromosome(shared_ptr<Chromosome> myChromsome);             // Remove a chromosome
        void addSickness();                                                    // Add a sickness
        void removeSickness();                                                 // Remove a sickness
        void move();                                                           // Ask the being to move
        bool isDead();                                                         // Is the being dead?

    private:
        string my_name;
        map<string, shared_ptr<Chromosome> > my_chromosomes;
        vector<Being *> my_parents;
        vector<Being *> my_children;

	//shared_ptr<Being> mate(Being &partner, string name);
};

#endif // __ALOBE__BEING__
