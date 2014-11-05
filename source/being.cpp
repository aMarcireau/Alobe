#include "being.h"

/**
 * Constructor
 */
Being::Being(string name, vector<shared_ptr<Chromosome> > chromosomes):
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
vector<shared_ptr<Chromosome> > Being::getChromosomes() const
{
	return my_chromosomes;
}

/**
 * Add a chromosome
 */
void Being::addChromosome(shared_ptr<Chromosome> chromosome)
{
	my_chromosomes.push_back(chromosome);
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
void Being::applyChanges(Stepper & stepper)
{
}

/**
 * Generate the being migration
 */
string Being::migrate(map<string, Tile *> neighboringTiles)
{
    return "east";
}


/**
* Generate being demi genome
*/
vector<shared_ptr<Chromosome> > Being::getBeingHalfChromosomes() const
{
	vector<shared_ptr<Chromosome> > BeingHalfChromosomes;

	for (int i = 0; this->getChromosomes().size(); ++i){
        vector<shared_ptr<Chromosome> > localChromosome;

        for (
			vector<shared_ptr<Chromosome> >::iterator chromosomesIterator = getChromosomes().begin();
			chromosomesIterator != getChromosomes().end();
		    ++chromosomesIterator
        ){
            if ((*chromosomesIterator)->getId() == i){
                localChromosome.push_back(*chromosomesIterator);
            }
        }

        BeingHalfChromosomes.push_back(localChromosome[static_cast<int>(rand())]);
    }

	return BeingHalfChromosomes;
}


/**
* Generate potential child chromosomes
*/
vector<shared_ptr<Chromosome> > Being::setChildChromosomes(Being & mate)
{
	vector<shared_ptr<Chromosome> > childChromosomes;

    childChromosomes = getBeingHalfChromosomes();
	for (
		vector<shared_ptr<Chromosome> >::iterator chromosomesIterator = mate.getBeingHalfChromosomes().begin();
		chromosomesIterator != mate.getBeingHalfChromosomes().end();
		++chromosomesIterator
    ){
		childChromosomes.push_back(*chromosomesIterator);
	}

    return childChromosomes;
}


/**
* Test if the current being will mate with an other specified being
*/
bool Being::isReadyToMate(Being & mate)
{
	//To be changed to use proba
	return true;
}

