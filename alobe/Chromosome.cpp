#include "Chromosome.h"

Chromosome::Chromosome(string name, string gene) : name(name), gene(gene)
{}

string Chromosome::getName() const
{
	return name;
}


string Chromosome::getGene() const
{
	return gene;
}