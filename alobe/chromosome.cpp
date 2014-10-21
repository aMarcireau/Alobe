#include "chromosome.h"

/**
 * Constructor
 */
Chromosome::Chromosome(string name, string gene):
    my_name(name),
    my_gene(gene)
{
}

/**
 * Getter fot the pair identifier
 */
string Chromosome::getName() const
{
	return my_name;
}

/**
 * Getter for the main gene
 */
string Chromosome::getGene() const
{
	return my_gene;
}
