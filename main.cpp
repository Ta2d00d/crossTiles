#include "board.h"
#include "tile.h"
#include "deck.h"
#include "player.h"
#include <cstdio>

void printScore(player one, player two)
{
	cout<<setw(12)<<"W - "<<one.getName()<<":  "<<one.getScore()<<setw(24)<<"B - "<<two.getName()<<":  "<<two.getScore()<<endl;
}

void countScore(deck d1, player *p1, player *p2)
{
	tile check;
	int w = 0;
	int b = 0;
	for(int i=1;i<DECKSIZE; i++)
	{
		check = d1.getTile(i);
		if(check.getOwner()==1)
		{
			w+=1;
		}
		else if(check.getOwner()==2)
		{
			b+=1;
		}
	}
	p1->setScore(w);
	p2->setScore(b);
}

void clearScreen()
{
	for(int i=0; i<20; i++)
		cout<<endl;
}

int main()
{
	string p;
	int col, row;
	char junk;

	player ps[1];
	cout<<"Player 1: Please enter a name"<<endl;
	cin>>p;
	ps[0].setName(p);
	ps[0].setScore(0);
	cout<<"Player 2: Please enter a name"<<endl;
	cin>>p;
	ps[1].setName(p);
	ps[1].setScore(0);
	getchar();

	board g1;
	g1.print();
	printScore(ps[0], ps[1]);

	tile t1;
	deck d1;
	for(int i=1;i<DECKSIZE;i++)
	{
		t1 = d1.getTile(i);
		t1.setOwner(1);
		d1.setOwner(i, 1);
		t1.print();
		cout<<ps[0].getName()<<" type a space to place tile: ";
		row = getchar();
		col = getchar();
		getchar();

		while(row<'A'||(row>='A'+BOARDSIZE && row<'a')||row>='a'+BOARDSIZE||col<'0'||col>='0'+BOARDSIZE)
		{
			cout<<row<<" "<<col<<"Invalid, please enter an available space from the board: "<<endl;
			cout<<"<A: "<<'A'<<" >A+SIZE: "<<'A'+BOARDSIZE<<" <a+SIZE: "<<'a'+BOARDSIZE<<" >a: "<<'a'<<endl;
			row = getchar();
			col = getchar();
			getchar();
		}

		if(row>'Z')
		{
			row = row - 'a';
		}
		else
		{
			row = row - 'A';
		}
		col = col - '0';
		d1 = g1.add(row, col, i, d1);
		clearScreen();
		g1.print(d1);
		countScore(d1, &ps[0], &ps[1]);
		printScore(ps[0], ps[1]);

		++i;
		t1 = d1.getTile(i);
		t1.setOwner(2);
		d1.setOwner(i, 2);
		t1.print();
		cout<<ps[1].getName()<<" type a space to place tile: ";
		row = getchar();
		col = getchar();
		getchar();

		while(row<'A'||(row>='A'+BOARDSIZE && row<'a')||row>='a'+BOARDSIZE||col<'0'||col>='0'+BOARDSIZE)
		{
			cout<<row<<" "<<col<<"Invalid, please enter an available space from the board: ";
			cout<<"<A: "<<'A'<<">A+SIZE: "<<'A'+BOARDSIZE<<"<a+SIZE: "<<'a'+BOARDSIZE<<">a: "<<'a'<<endl;
			row = getchar();
			col = getchar();
			getchar();
		}

		if(row>'Z')
		{
			row = row - 'a';
		}
		else
		{
			row = row - 'A';
		}
		col = col - '0';
		d1 = g1.add(row, col, i, d1);
		clearScreen();
		g1.print(d1);
		countScore(d1, &ps[0], &ps[1]);
		printScore(ps[0], ps[1]);
	}
	return 0;
}
