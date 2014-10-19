#include "Land.h"
#include "Tile.h"

using namespace std;

Land::Land(int w, int h) : width(w), height(h)
{	
	//Verifier que w et h sont non nuls
}


//ok
 int Land::getWidth() const
 {
	 return width;
 }

//ok
 int Land::getHeight() const
 {
	 return height;
 }

//ok
 int Land::getTilesNumber() const
 {
	 return height * width;
 }

 void Land::generate()
 {
	 for (int y = 0; y < height; y++){
		 for (int x = 0; x < width; x++){
			 
			 vector<int> coordinates;
			 coordinates.push_back(x);
			 coordinates.push_back(y);
			 tileLand.insert(pair <vector<int>, unique_ptr<Tile> >(coordinates, make_unique<Tile>(x, y)));
		 }
	 }
 }
