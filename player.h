#ifndef _PLAYER_H
#define _PLAYER_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class player
{
public:
	player();
	player(string);
	string getName();
	int getScore();
	void setName(string);
	void setScore(int);

private:
	string name;
	int score;
};


#endif
