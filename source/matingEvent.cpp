#include "matingEvent.h"

/**
* Constructor
*/
MatingEvent::MatingEvent() :
	PeriodicEvent()
{
}

/**
* Get all the beings on the land to maybe mate
*/
void MatingEvent::filteredAction(Actor & actor)
{
	Population & population(dynamic_cast<Population &>(actor));
	// Do action on all the tiles
	for (unsigned long x = 0; x < population.getLand()->getWidth(); ++x) {
		for (unsigned long y = 0; y < population.getLand()->getHeight(); ++y) {
			map<string, Tile *> neighboringTiles = population.getLand()->getNeighboringTiles(x, y);
			// Get all the beings on a tile
			vector<Being *> beings = neighboringTiles["here"]->getBeings();
			// Iteration on all beings
			for (
				vector<Being *>::iterator beingIterator = beings.begin();
				beingIterator != beings.end();
				++beingIterator
				) {
				//Iteration on all beings that haven't met the previous being yet
				for (
					vector<Being *>::iterator otherBeingsIterator = beingIterator;
					otherBeingsIterator != beings.end();
					++otherBeingsIterator
					){	
					//Test if the being want to mate with an other being
					if ((*beingIterator)->isReadyToMate(**otherBeingsIterator))
						{
							// Creation of the child chromosomes
							auto childChromosomes = (*beingIterator)->setChildChromosomes(**otherBeingsIterator);
							//Creation of the new being on the current tile
							population.addBeing(make_unique<Being>(to_string(rand()), childChromosomes), x, y);
						}
					}
				}
			}
		}
	}
