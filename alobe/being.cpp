#include "Being.h"

/**
 * Constructor
 */
Being::Being(string name, map< string, shared_ptr<Chromosome> > chromosomes) :
    _name(name),
    _chromosomes(chromosomes)
{
}

/**
 * Getter for the being name
 */
string Being::getName() const
{
	return _name;
}

/**
 * Getter for the being children
 */
vector<Being *> Being::getChildren() const
{
	return _children;
}

/**
 * Getter for the being parents
 */
vector<Being *> Being::getParents() const
{
	return _parents;
}

/**
 * Getter for the being chromosomes
 */
map<string, shared_ptr<Chromosome> > Being::getChromosomes() const
{
	return _chromosomes;
}

/**
 * Add a chromosome
 */
void Being::addChromosome(shared_ptr<Chromosome> chromosome)
{
	_chromosomes.insert(pair<string, shared_ptr<Chromosome> >((*chromosome).getName(), chromosome));
}

/**
 * Remove a chromosome
 */
void Being::removeChromosome(shared_ptr<Chromosome> myChromsome)
{
	_chromosomes.erase((*myChromsome).getName());
}

/**
 * Add a sickness
 */
void Being::addSickness()
{
}

/**
 * Remove a sickness
 */
void Being::removeSickness()
{
}

/**
 * Ask the being to move
 */
void Being::move()
{
}

///**
// * Ask the being to move
// */
//shared_ptr<Being> Being::mate(Being &partner, string name)
//{
//}
