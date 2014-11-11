#include "being.h"

/**
 * Constructor
 */
Being::Being(string name, map<string, vector<string> > chromosomes):
    Actor(),
    my_name(name),
    my_chromosomes(chromosomes),
    my_dead(false),
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
map<string, vector<string> > Being::getChromosomes() const
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
 * Add a state
 */
void Being::addState(string stateName, unique_ptr<State> state)
{
    my_states[stateName] = move(state);
}

/**
 * Remove a state by name
 */
void Being::removeState(string stateName)
{
    if (!hasState(stateName)) {
        throw logic_error("State map key not found");
    }

	my_states.erase(stateName);
}

/**
 * Getter for a behavior
 */
Behavior * Being::getBehavior(string behaviorName)
{
    if (!hasBehavior(behaviorName)) {
        throw logic_error("Behavior map key not found");
    }

    return my_behaviors[behaviorName].get();
}

/**
 * Is the behavior defined for the being ?
 */
bool Being::hasBehavior(string behaviorName) const
{
    return (my_behaviors.find(behaviorName) == my_behaviors.end());
}

/**
 * Add a behavior
 */
void Being::addBehavior(string behaviorName, unique_ptr<Behavior> behavior)
{
    my_behaviors[behaviorName] = move(behavior);
}

/**
 * Remove a behavior by name
 */
void Being::removeBehavior(string behaviorName)
{
    if (!hasBehavior(behaviorName)) {
        throw logic_error("Behavior map key not found");
    }

	my_behaviors.erase(behaviorName);
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
 * Is the being willing to mathe with the given other being?
 */
bool Being::isWillingToMateWith(Being & mate)
{
    return (rand() > (0.3 * RAND_MAX));
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
