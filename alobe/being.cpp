#include "Being.h"

/**
 * Constructor
 */
Being::Being(string name, map< string, shared_ptr<Chromosome> > chromosomes) :
    my_name(name),
    my_chromosomes(chromosomes)
{
}

/**
 * Getter for the being name
 */
string Being::getName() const
{
	return my_name;
}

/**
 * Getter for the being children
 */
vector<Being *> Being::getChildren() const
{
	return my_children;
}

/**
 * Getter for the being parents
 */
vector<Being *> Being::getParents() const
{
	return my_parents;
}

/**
 * Getter for the being chromosomes
 */
map<string, shared_ptr<Chromosome> > Being::getChromosomes() const
{
	return my_chromosomes;
}

/**
 * Add a chromosome
 */
void Being::addChromosome(shared_ptr<Chromosome> chromosome)
{
	my_chromosomes.insert(pair<string, shared_ptr<Chromosome> >((*chromosome).getId(), chromosome));
}

/**
 * Remove a chromosome by reference
 */
void Being::removeChromosome(Chromosome & chromsome)
{
	my_chromosomes.erase(chromsome.getId());
}

/**
 * Remove a chromosome by id
 */
void Being::removeChromosome(string chromsomeId)
{
	my_chromosomes.erase(chromsomeId);
}

/**
 * Add a state
 */
void Being::addState(unique_ptr<State> state)
{
	my_states.insert(pair<string, unique_ptr<State> >(state.get()->getId(), move(state)));
}

/**
 * Remove a state by reference
 */
void Being::removeState(State & state)
{
	my_chromosomes.erase(state.getId());
}

/**
 * Remove a state by id
 */
void Being::removeState(string stateId)
{
	my_chromosomes.erase(stateId);
}

/**
 * Generate the being migration
 */
void Being::migrate()
{
}

/**
 * Is the being dead?
 */
bool Being::isDead()
{
    return false;
}
