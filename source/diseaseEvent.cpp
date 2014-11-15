#include "diseaseEvent.h"

/**
* Constructor
*/
DiseaseEvent::DiseaseEvent() :
PeriodicEvent()
{
}

/**
* For every being that have the state 'alobe', the event decrement the state counter. 
* If multiple beings are on the same tile, the beings that have the state 'alobe' will transmit it to 10% other healthy beings. 
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

		if (beings[beingIndex]->getState("alobe")->getValue() == 0)
		{
			beings[beingIndex]->kill();
		}
	}
}
