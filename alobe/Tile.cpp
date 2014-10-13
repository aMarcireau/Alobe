#include "Tile.h"
#include <string>
using namespace std;


Tile::Tile(int x, int y) : x(x), y(y)
{}


int Tile::getX() const
{
	return x;
}


int Tile::getY() const
{
	return y;
}

string Tile::confirm()
{
	string str("on est sur la tile : ");
	return  str+to_string(this->getX())+" - "+to_string(this->getY());
};