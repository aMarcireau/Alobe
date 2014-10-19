#include "chromosome.h"

/**
 * Constructor
 */
Chromosome::Chromosome(string name, string gene):
    _name(name),
    _gene(gene)
{
}

/**
 * Getter fot the pair identifier
 */
string Chromosome::getName() const
{
	return _name;
}

/**
 * Getter for the main gene
 */
string Chromosome::getGene() const
{
	return _gene;
}
