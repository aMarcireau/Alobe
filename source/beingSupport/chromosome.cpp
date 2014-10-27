#include "chromosome.h"

/**
 * Constructor
 */
Chromosome::Chromosome(string id, string gene):
    my_id(id),
    my_gene(gene)
{
}

/**
 * Getter fot the pair identifier
 */
string Chromosome::getId() const
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
