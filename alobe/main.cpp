#include "simulation.h"
#include "stepper.h"
#include "actor.h"
#include "Land.h"
#include "Tile.h"

using namespace std;

int main()
{

    unique_ptr<Simulation> simulation = make_unique<Simulation>(make_unique<Stepper>());
	int height, width;

	cout << "Enter a height for your land: " << endl;
	cin >> height;
	cout << "Enter a width for your land: " << endl;
	cin >> width;
	Land land(height, width);
	cout << "the land width is " << land.getWidth() << endl;
	cout << "The land's height is " << land.getHeight() << endl;
	cout << "The number of tiles in this land is  " << land.getTilesNumber() << endl;
	cout << "Filling of the land with tiles! " << endl;
	land.generate();
	cout << "The land is filled! " << endl;
	
	for (map<vector<int>, unique_ptr<Tile> >::iterator it = land.tileLand.begin(); it != land.tileLand.end(); ++it){
		Tile * tileTest = (it->second).get();
		cout << (*tileTest).confirm() << '\n';
	}

	simulation->toStep(10);
	return 0;
}
