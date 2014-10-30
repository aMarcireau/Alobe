#include "being.h"

/**
 * Constructor
 */
Being::Being(string name, map<string, shared_ptr<Chromosome> > chromosomes):
    Actor(),
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
	my_states.erase(state.getId());
}

/**
 * Remove a state by id
 */
void Being::removeState(string stateId)
{
	my_states.erase(stateId);
}

/**
 * Is the being dead?
 */
bool Being::isDead()
{
    return false;
}

/**
 * Apply changes after a step
 */
void Being::applyChanges()
{
}

/**
 * Generate the being migration
 */
string Being::migrate(map<string, Tile *> neighboringTiles)
{
    return "east";
}
