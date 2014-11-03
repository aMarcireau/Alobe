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
        Chromosome(unsigned int id, string gene);
        unsigned int getId() const;                 // Getter fot the pair identifier
        string getGene() const;               // Getter for the main gene

    private:
        unsigned int my_id;
        string my_gene;
};

#endif // __ALOBE__CHROMOSOME__
