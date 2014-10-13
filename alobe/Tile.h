#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;

/* The tiles are hexagonale tiles


          *
      *       *
    *           *
	*			*
	*           *
	  *       *
	      *

*/


class Tile
{
public:
	Tile(int x, int y);
	int getX() const;
	int getY() const;
	string confirm();

private:
	int x, y;
};
