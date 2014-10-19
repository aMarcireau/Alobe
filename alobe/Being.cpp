#include "Being.h"

Being::Being(string name, map< string, shared_ptr<Chromosome> > chromosomes) : name(name), chromosomes(chromosomes)
{}


string Being::getName() const
{
	return name;
}

vector<Being * > Being::getParents() const
{
	return parents;
}

vector<Being * > Being::getChildren() const
{
	return children;
}

map< string, shared_ptr<Chromosome> > Being::getChromosomes() const
{
	return chromosomes;
}

void Being::addChromosome(shared_ptr<Chromosome> newChromosome)
{
	chromosomes.insert(pair<string, shared_ptr<Chromosome> >( (*newChromosome).getName(), newChromosome));
}

void Being::removeChromosome(shared_ptr<Chromosome> myChromsome)
{
	chromosomes.erase((*myChromsome).getName());
}


void Being::addSickness()
{}


void Being::removeSickness()
{}


void Being::move()
{}


shared_ptr<Being> Being::mate(Being &partner, string name)4
{}