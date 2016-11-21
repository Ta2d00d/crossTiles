#ifndef _TILE_H
#define _TILE_H
#include <iostream>
#include <iomanip>
using namespace std;
class tile
{
public:
	tile();
	int getNorth();
	int getEast();
	int getSouth();
	int getWest();
	int getOwner();
	void setNorth(int);
	void setEast(int);
	void setSouth(int);
	void setWest(int);
	void setOwner(int);
	void print();
private:
	int north;
	int east;
	int south;
	int west;
	int owner; //0 for no owner, 1 for white, 2 for black
};


#endif
