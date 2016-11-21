#ifndef _BOARD_H
#define _BOARD_H
#include <iostream>
#include <iomanip>
#include "deck.h"
#include "tile.h"
using namespace std;
#define BOARDSIZE 5
class board
{
public:
	board();
	board(bool directed);
	deck add(int src, int dst, int ind, deck d1);
	void print();
	void print(deck d1);
private:
	//use a pointer to a pointer so that we can dynamically
	//create a 2d array for our matrix
	int **matrix;
	//if we do not use the above we would need to hardcode the
	//size of the matrix into the declaration
	//int matrix[BOARDSIZE][BOARDSIZE];

	//signify if we have a directed board or not
	bool directed;
};


#endif
