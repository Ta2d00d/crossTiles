#include "deck.h"
deck::deck()
{
	tile t;
	int val;
	srand(time(0));
	for(int i=1;i<DECKSIZE;i++)
	{
		val = (rand()%6) + 1;
		t.setNorth(val);
		val = (rand()%6) + 1;
		t.setEast(val);
		val = (rand()%6) + 1;
		t.setSouth(val);
		val = (rand()%6) + 1;
		t.setWest(val);
		tileDeck[i] = t;
	}
}

tile deck::getTile(int ind)
{
	return tileDeck[ind];
}

int deck::getOwner(int ind)
{
	tile t;
	t = tileDeck[ind];
	return t.getOwner();
}

void deck::setOwner(int ind, int player)
{
	tileDeck[ind].setOwner(player);
}

void deck::print()
{
	tile t;

	for(int i=0;i<DECKSIZE;i++)
	{
		t = tileDeck[i];
		cout<<i<<endl;

		cout<<"   ----"<<endl;
		cout<<"   | "<<t.getNorth()<<"|"<<endl; //pop north
		cout<<"---    ---"<<endl;
		cout<<"|"<<t.getWest()<<"   W   "<<t.getEast()<<"|"<<endl; //pop west, east
		cout<<"---    ---"<<endl;
		cout<<"   | "<<t.getSouth()<<"|"<<endl;  //pop south
		cout<<"   ----"<<endl;
	}

}
