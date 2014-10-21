#include "state.h"

/**
 * Constructor
 */
State::State(string id):
    my_id(id)
{
}

/**
 * Getter fot the pair identifier
 */
string State::getId() const
{
	return my_id;
}
