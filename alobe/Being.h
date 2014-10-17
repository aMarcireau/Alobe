#include <string>
#include <map>
#include "Chromosome.h"
#include "Tile.h"
#include<memory>
#include <vector>
using namespace std;

class Being
{
private:
	string name;
	map< int, unique_ptr<Chromosome> > chromosomes;
	vector< shared_ptr<Being>> parents;
	vector< shared_ptr<Being>> children;

public:
	Being(string name, map< int, unique_ptr<Chromosome> > chromosomes);
	string getName() const;
	vector< shared_ptr<Being>> getParents() const;
	vector< shared_ptr<Being>> getChildren() const;
	map< int, unique_ptr<Chromosome> > getChromosomes() const;
	Tile* getPosition();

	void addChromosome(Chromosome &Chromsome);
	void removeChromosome(Chromosome &Chromsome);

	void addSickness();
	void removeSickness();

	void move();

	shared_ptr<Being> mate(Being &partner, string name);
};