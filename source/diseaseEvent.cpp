#include "diseaseEvent.h"

/**
 * Constructor
 */
DiseaseEvent::DiseaseEvent():
    PeriodicEvent()
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
    vector<Being *> healthyBeings;
	vector<Being *> sickBeings;
	for (
        vector<Being *>::iterator beingIterator = beings.begin();
        beingIterator != beings.end();
        ++beingIterator
    ) {
		if ((*beingIterator)->hasState("alobe")) {
			sickBeings.push_back((*beingIterator));
		} else {
			healthyBeings.push_back((*beingIterator));
		}
	}

	unsigned long healthyBeingsNumber = healthyBeings.size();
	unsigned long sickBeingsNumber = sickBeings.size();

	for (
		unsigned long beingIndex = 0;
		beingIndex < ceil(healthyBeingsNumber * 0.1);
		++beingIndex
		){
		healthyBeings[beingIndex]->addState("alobe", make_unique<State>(5));
	}

	for (
		unsigned long beingIndex = 0;
		beingIndex < sickBeingsNumber;
		++beingIndex
    ){
		sickBeings[beingIndex]->getState("alobe")->decrement(1);

		if (sickBeings[beingIndex]->getState("alobe")->getValue() == 0) {
			sickBeings[beingIndex]->kill();
		}
	}
}
