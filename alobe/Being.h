#include <string>
#include <map>
#include "Chromosome.h"
#include "Tile.h"
#include<memory>
#include <vector>
#include "actor.h"
using namespace std;

class Being : public Actor
{
private:
	string name;
	map< string, shared_ptr<Chromosome> > chromosomes;
	vector< Being *> parents;
	vector< Being *> children;

public:
	Being(string name, map< string, shared_ptr<Chromosome> > chromosomes);
	string getName() const;
	vector< Being *> getParents() const;
	vector< Being *> getChildren() const;
	map< string, shared_ptr<Chromosome> > getChromosomes() const;

	void addChromosome(shared_ptr<Chromosome> newChromsome);
	void removeChromosome(shared_ptr<Chromosome> myChromsome);

	void addSickness();
	void removeSickness();

	void move();

	//shared_ptr<Being> mate(Being &partner, string name);
};
