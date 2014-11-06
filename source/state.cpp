#include "state.h"

/**
 * Constructor
 */
State::State(unsigned long value):
    my_value(value),
    mod_value(value)
{
}

/**
 * Getter fot the state value
 */
unsigned long State::getValue() const
{
	return my_value;
}

/**
 * Apply changes after a step
 */
void State::applyChanges()
{
	my_value = mod_value;
}

/**
 * Decrement the state value. The value is set to 0
 * if it reaches a negative value
 */
void State::decrement(unsigned long amount)
{
    long long difference = mod_value - amount;

    if (difference >= 0) {
        mod_value = static_cast<unsigned long>(difference);
    } else {
        mod_value = 0;
    }
}
