#ifndef _DECK_H
#define _DECK_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "tile.h"
using namespace std;
#define DECKSIZE 25
class deck
{
public:
	deck();
	tile getTile(int);
	int getOwner(int);
	void setOwner(int, int);
	void print();
private:
	tile tileDeck[DECKSIZE];
};


#endif
