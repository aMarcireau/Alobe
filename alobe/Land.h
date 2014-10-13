#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "Tile.h"
using namespace std;

class Land
{
public:
	Land(int width, int height);
	int getWidth() const;
	int getHeight() const;
	Tile * getTile(int x, int y);

	int getTilesNumber() const;
	void generate();

public:
	int width, height;
	map<vector<int>, unique_ptr<Tile> > tileLand;
};

