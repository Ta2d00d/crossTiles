#include "tile.h"
tile::tile()
{
	
	north = 0;
	east = 0;
	south = 0;
	west = 0;
	owner = 0;
		
}

int tile::getNorth()
{
	return north;
}

int tile::getEast()
{
	return east;
}

int tile::getSouth()
{
	return south;
}

int tile::getWest()
{
	return west;
}

int tile::getOwner()
{
	return owner;
}

void tile::setNorth(int x)
{
	north = x;
}

void tile::setEast(int x)
{
	east = x;
}

void tile::setSouth(int x)
{
	south = x;
}

void tile::setWest(int x)
{
	west = x;
}

void tile::setOwner(int x)
{
	owner = x;
}

void tile::print()
{
	cout<<"   ----"<<endl;
	cout<<"   | "<<north<<"|"<<endl; //pop north
	cout<<"---    ---"<<endl;
	if(owner==1)
	{
		cout<<"|"<<west<<"   W   "<<east<<"|"<<endl; //pop west, east
	}
	else if(owner==2)
	{
		cout<<"|"<<west<<"   B   "<<east<<"|"<<endl; //pop west, east
	}
	else
	{
		cout<<"|"<<west<<"       "<<east<<"|"<<endl; //pop west, east
	}
	cout<<"---    ---"<<endl;
	cout<<"   | "<<south<<"|"<<endl;  //pop south
	cout<<"   ----"<<endl;
}




/*
	----
	| 1|
     ---    ---
     |4   W   2|
     ---    ---
	| 3|
	----

*/
