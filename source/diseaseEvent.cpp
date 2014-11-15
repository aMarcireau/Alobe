#include "diseaseEvent.h"

/**
* Constructor
*/
DiseaseEvent::DiseaseEvent() :
PeriodicEvent()
{
}

/**
* Get all the beings on the land to maybe share disease
*/
void DiseaseEvent::filteredAction(Actor & actor)
{
	Tile & tile(dynamic_cast<Tile &>(actor));
	vector<Being *> beings = tile.getBeings();
	vector<Being *> healthyBeings;
	vector<Being *> sickBeings;

	unsigned long beingsNumber = beings.size();

	for (
		unsigned long beingIndex = 0;
		beingIndex < beingsNumber;
		++beingIndex
		) {
		if (beings[beingIndex]->hasState("alobe")){
			sickBeings.push_back(beings[beingIndex]);
		}
		else{
			healthyBeings.push_back(beings[beingIndex]);
		}
	}

	unsigned long healthyBeingsNumber = healthyBeings.size();
	unsigned long sickBeingsNumber = sickBeings.size();

	for (
		unsigned long beingIndex = 0;
		beingIndex < healthyBeingsNumber;
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

		if (beings[beingIndex]->getState("alobe")->getValue() == 0)
		{
			beings[beingIndex]->kill();
		}
	}
}
