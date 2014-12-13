#include "diseaseEvent.h"

/**
 * Constructor
 */
DiseaseEvent::DiseaseEvent(
    unique_ptr<TabulatedDistribution> transmissionDistribution,
    unique_ptr<TabulatedDistribution> remissionDistribution,
    unique_ptr<TabulatedDistribution> deathDistribution
):
    PeriodicEvent(),
    my_transmissionDistribution(move(transmissionDistribution)),
    my_remissionDistribution(move(remissionDistribution)),
    my_deathDistribution(move(deathDistribution))
{
}

/**
 * Get all the nearest beings to share disease
 * Actor must be a Tile
 *
 * Decrements the 'alobe' state counter for each sick being
 * Also, transmits the disease to healthy beings sharing a tile with sick ones
 */
void DiseaseEvent::filteredAction(Actor & actor)
{
	Tile & tile(dynamic_cast<Tile &>(actor));

    vector<Being *> beings = tile.getBeings();
    unsigned long sickBeingsNumber = 0;
    for (
        vector<Being *>::iterator beingIterator = beings.begin();
        beingIterator != beings.end();
        ++beingIterator
    ) {
        if ((*beingIterator)->hasState("sick")) {
            (*beingIterator)->getState("sick")->decrement();
            sickBeingsNumber++;
            
            if (my_remissionDistribution->getDecision()) {
                (*beingIterator)->removeState("sick");
                (*beingIterator)->addState("cured", make_unique<State>());
            } else if (my_deathDistribution->getDecision((*beingIterator)->getState("sick")->getValue())) {
                (*beingIterator)->kill();
            }
        }
    }

    for (
        vector<Being *>::iterator beingIterator = beings.begin();
        beingIterator != beings.end();
        ++beingIterator
    ) {
        if (!(*beingIterator)->hasState("sick") && !(*beingIterator)->hasState("cured")) {

            for (
                unsigned long sickIndex = 0;
                sickIndex < sickBeingsNumber;
                ++sickIndex
            ) {
                if (my_transmissionDistribution->getDecision()) {
                    (*beingIterator)->addState("sick", make_unique<State>(DISEASE_ALWAYS_DEAD));
                }
            }
        }
    }
}
