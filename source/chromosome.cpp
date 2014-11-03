#include "chromosome.h"

/**
 * Constructor
 */
Chromosome::Chromosome(unsigned int id, string gene):
    my_id(id),
    my_gene(gene)
{
}

/**
 * Getter fot the pair identifier
 */
unsigned int Chromosome::getId() const
{
	return my_id;
}

/**
 * Getter for the main gene
 */
string Chromosome::getGene() const
{
	return my_gene;
}
