#ifndef __ALOBE__CHROMOSOME__
#define __ALOBE__CHROMOSOME__

#include <string>

using namespace std;

/**
 * Chromosome
 *
 * A chromosome carrying genetic data
 */
class Chromosome
{
    public:
        Chromosome(string name, string gene);
        string getName() const;               // Getter fot the pair identifier
        string getGene() const;               // Getter for the main gene

    private:
        string my_name;
        string my_gene;
};

#endif // __ALOBE__CHROMOSOME__
