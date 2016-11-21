#include "board.h"

board::board()
{
	//create an array of integer pointers, this takes care of
	//the first pointer in our double pointer
	matrix = new int*[BOARDSIZE];
	//for each index in that array create an array of plain
	//integers, not pointers to integers
	for(int i=0;i<BOARDSIZE;i++)
		matrix[i] = new int[BOARDSIZE];

	//initialize all of the elements in our matrix to 0
	for(int i=0;i<BOARDSIZE;i++)
		for(int x=0;x<BOARDSIZE;x++)
			matrix[i][x] = 0;

}

board::board(bool dir)
{
	//overloaded constructor for use when we may have a directed board
	board();
	directed = dir;
}

deck board::add(int row, int col, int ind, deck d1)
{
	tile cur, check;

	//set tile
	matrix[row][col] = ind;

	//compare current tile to neighbors - change owner if needed
	cur = d1.getTile(ind);

	//North
	if(row>0)
	{
		check = d1.getTile(matrix[row-1][col]);
		if(cur.getNorth() > check.getSouth())
		{
			check.setOwner(cur.getOwner());
			d1.setOwner(matrix[row-1][col], cur.getOwner());
		}
	}
	//East
	if(col<BOARDSIZE-1)
	{
		check = d1.getTile(matrix[row][col+1]);
		if(cur.getEast() > check.getWest())
		{
			check.setOwner(cur.getOwner());
			d1.setOwner(matrix[row][col+1], cur.getOwner());
		}
	}
	//South
	if(row<BOARDSIZE-1)
		{
			check = d1.getTile(matrix[row+1][col]);
			if(cur.getSouth() > check.getNorth())
			{
				check.setOwner(cur.getOwner());
				d1.setOwner(matrix[row+1][col], cur.getOwner());
			}
		}
	//West
	if(col>0)
	{
		check = d1.getTile(matrix[row][col-1]);
		if(cur.getWest() > check.getEast())
		{
			check.setOwner(cur.getOwner());
			d1.setOwner(matrix[row][col-1], cur.getOwner());
		}
	}
			/*cout<<"tileOwner: "<<check.getOwner()<<endl;
			cout<<"deckOwner: "<<d1.getOwner(matrix[row-1][col])<<endl;

			cout<<"curTileOwner: "<<cur.getOwner()<<endl;
			cout<<"deckOwner: "<<d1.getOwner(ind)<<endl;*/

	return d1;
}

void board::print(deck d1)
{
	tile cur;
	char row;

	cout<<" ";
	for(int i=0; i<BOARDSIZE; i++)
		cout<<"------------";
	cout<<endl;

	for(int i=0; i<BOARDSIZE; i++)
	{
		row = i+'A';
		cout<<"|";

		for(int x=0; x<BOARDSIZE; x++)
		{
			if(!matrix[i][x])
			{
				cout<<setw(12)<<"|";
			}
			else
			{
				cur = d1.getTile(matrix[i][x]);
				cout<<"    ---    |";
			}
		}
				cout<<endl;
				cout<<"|";
		for(int x=0; x<BOARDSIZE; x++)
		{
			if(!matrix[i][x])
			{
				cout<<setw(12)<<"|";
			}
			else
			{
				cur = d1.getTile(matrix[i][x]);
				cout<<"    |"<<cur.getNorth()<<"|    |";
			}
		}
				cout<<endl;
				cout<<"|";
		for(int x=0; x<BOARDSIZE; x++)
		{

			if(!matrix[i][x])
			{
				cout<<setw(12)<<"|";
			}
			else
			{
				cur = d1.getTile(matrix[i][x]);
				cout<<" ---   --- |";
			}
		}
				cout<<endl;
				cout<<"|";


		for(int x=0; x<BOARDSIZE; x++)
		{
			if(!matrix[i][x])
			{
				cout<<"     "<<row<<x<<"    |";
			}
			else
			{
			cur = d1.getTile(matrix[i][x]);
				if(cur.getOwner()==1)
				{
					cout<<" |"<<cur.getWest()<<"  W  "<<cur.getEast()<<"| |";
				}
				else if(cur.getOwner()==2)
				{
					cout<<" |"<<cur.getWest()<<"  B  "<<cur.getEast()<<"| |";
				}
				else
				{
					cout<<" |"<<cur.getWest()<<"     "<<cur.getEast()<<"| |";
				}
			}
		}
		cout<<endl;
		cout<<"|";
		for(int x=0; x<BOARDSIZE; x++)
		{

			if(!matrix[i][x])
			{
				cout<<setw(12)<<"|";
			}
			else
			{
				cur = d1.getTile(matrix[i][x]);
				cout<<" ---   --- |";
			}
		}
				cout<<endl;
				cout<<"|";
		for(int x=0; x<BOARDSIZE; x++)
		{

			if(!matrix[i][x])
			{
				cout<<setw(12)<<"|";
			}
			else
			{
				cur = d1.getTile(matrix[i][x]);
				cout<<"    |"<<cur.getSouth()<<"|    |";
			}
		}
				cout<<endl;
				cout<<"|";
		for(int x=0; x<BOARDSIZE; x++)
		{

			if(!matrix[i][x])
			{
				cout<<setw(12)<<"|";
			}
			else
			{
				cur = d1.getTile(matrix[i][x]);
				cout<<"    ---    |";
			}
		}
				cout<<endl;
				cout<<" ";

		for(int x=0; x<BOARDSIZE; x++)
			cout<<"------------";
		cout<<endl;
	}
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

void board::print()
{
	char row;

	cout<<" ";
	for(int i=0; i<BOARDSIZE; i++)
		cout<<"------------";
	cout<<endl;

	for(int i=0; i<BOARDSIZE; i++)
	{
		row = i+'A';
		cout<<"|";

		for(int x=0; x<BOARDSIZE; x++)
		{
			cout<<setw(12)<<"|";
		}
				cout<<endl;
				cout<<"|";
		for(int x=0; x<BOARDSIZE; x++)
		{
				cout<<setw(12)<<"|";
		}
				cout<<endl;
				cout<<"|";
		for(int x=0; x<BOARDSIZE; x++)
		{

				cout<<setw(12)<<"|";
		}
				cout<<endl;
				cout<<"|";


		for(int x=0; x<BOARDSIZE; x++)
		{
			cout<<"     "<<row<<x<<"    |";
		}
		cout<<endl;

		cout<<"|";
		for(int x=0; x<BOARDSIZE; x++)
			cout<<setw(12)<<"|";
		cout<<endl;
		cout<<"|";
		for(int x=0; x<BOARDSIZE; x++)
			cout<<setw(12)<<"|";
		cout<<endl;
		cout<<"|";
		for(int x=0; x<BOARDSIZE; x++)
			cout<<setw(12)<<"|";
		cout<<endl;
		cout<<" ";

		for(int x=0; x<BOARDSIZE; x++)
			cout<<"------------";
		cout<<endl;
	}
}

