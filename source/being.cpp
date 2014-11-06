#include "being.h"

/**
 * Constructor
 */
Being::Being(string name, vector<shared_ptr<Chromosome> > chromosomes):
    Actor(),
    my_name(name),
    my_chromosomes(chromosomes),
    my_dead(false),
    my_behaviours(map<string, shared_ptr<Behaviour> >()),
    my_states(map<string, unique_ptr<State> >()),
    my_parents(vector<Being *>()),
    my_children(vector<Being *>())
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
 * Getter for the being chromosomes
 */
vector<shared_ptr<Chromosome> > Being::getChromosomes() const
{
	return my_chromosomes;
}

/**
 * Is the being dead?
 */
bool Being::isDead()
{
    return my_dead;
}

/**
 * Kill the being
 */
void Being::kill()
{
    my_dead = true;
}

/**
 * Getter for a behaviour
 */
shared_ptr<Behaviour> Being::getBehaviour(string behaviourName)
{
    if (my_behaviours.find(behaviourName) == my_behaviours.end()) {
        throw logic_error("Behaviours map key not found");
    }

    return my_behaviours[behaviourName];
}

/**
 * Add a behaviour
 */
void Being::addBehaviour(string behaviourName, shared_ptr<Behaviour> behaviour)
{
    my_behaviours[behaviourName] = behaviour;
}

/**
 * Getter for a state
 */
State * Being::getState(string stateName)
{
    if (!hasState(stateName)) {
        throw logic_error("State map key not found");
    }

    return my_states[stateName].get();
}

/**
 * Is the state defined for the being ?
 */
bool Being::hasState(string stateName) const
{
    return (my_states.find(stateName) == my_states.end());
}

/**
 * Remove a state by id
 */
void Being::removeState(string stateName)
{
    if (!hasState(stateName)) {
        throw logic_error("State map key not found");
    }

	my_states.erase(stateName);
}

/**
 * Getter for the being parents
 */
vector<Being *> Being::getParents() const
{
	return my_parents;
}

/**
 * Add a parent
 */
void Being::addParent(Being & parent)
{
	my_parents.push_back(&parent);
}

/**
 * Getter for the being children
 */
vector<Being *> Being::getChildren() const
{
	return my_children;
}

/**
 * Add a child
 */
void Being::addChild(Being & child)
{
	my_children.push_back(&child);
}

/**
 * Apply changes after a step
 */
void Being::applyChanges(Stepper & stepper)
{
    for (
        map<string, unique_ptr<State> >::iterator idAndStateIterator = my_states.begin();
        idAndStateIterator != my_states.end();
        ++idAndStateIterator
    ) {
        (idAndStateIterator->second)->applyChanges();
    }
}


/**
 * Generate the being migration

string Being::migrate(map<string, Tile *> neighboringTiles)
{
	vector<string> direction; 
	direction.push_back("east"); 
	direction.push_back("north");
	direction.push_back("west");
	direction.push_back("south");
	direction.push_back("here");
	unsigned int randomNumber = rand() % 5;
	return direction[randomNumber];
}


* Generate being demi genome

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



* Generate potential child chromosomes

vector<shared_ptr<Chromosome> > Being::setChildChromosomes(Being & mate)
{
	vector<shared_ptr<Chromosome> > childChromosomes;
	vector<shared_ptr<Chromosome> > mateHalfChromosomes = mate.getBeingHalfChromosomes();
    childChromosomes = getBeingHalfChromosomes();
	for (
		vector<shared_ptr<Chromosome> >::iterator chromosomesIterator = mateHalfChromosomes.begin();
		chromosomesIterator != mateHalfChromosomes.end();
		++chromosomesIterator
    ){
		childChromosomes.push_back(*chromosomesIterator);
	}

    return childChromosomes;
}



* Test if the current being will mate with an other specified being

bool Being::isReadyToMate(Being & mate)
{
	unsigned int proba = rand() % 100;
	if (proba < 30){
		return true;
	} else { 
		return false;
	}	
}
*/
