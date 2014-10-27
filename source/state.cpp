#include "state.h"

/**
 * Constructor
 */
State::State(string id, unsigned long property):
    my_id(id),
    my_property(property),
    mod_property(property)
{
}

/**
 * Getter fot the state identifier
 */
string State::getId() const
{
	return my_id;
}

/**
 * Getter fot the state property
 */
unsigned long State::getProperty() const
{
	return my_property;
}

/**
 * Apply changes after a step
 */
void State::applyChanges()
{
	my_property = mod_property;
}

/**
 * Decrement the state property. The property is set to 0
 * if it reaches a negative value
 */
void State::decrement(unsigned long value)
{
    long long difference = mod_property - value;

    if (difference >= 0) {
        mod_property = static_cast<unsigned long>(difference);
    } else {
        mod_property = 0;
    }
}
