#include "migration.h"

/**
 * Constructor
 */
Migration::Migration():
    Behavior(),
    my_tokenDistribution(make_unique<TokenDistribution<Tile *> >())
{
}
