#include <string>
using namespace std;

class Chromosome
{
private:
	// name: string, chromosome pair identifier
	// gene : string, chromosome main gene
	string name;
	string gene;

public:
	Chromosome(string name, string gene);
	string getName() const;
	string getGene() const;
};