#include "player.h"

player::player()
{
	
	name = "Player";
	score = 0;
		
}

string player::getName()
{
	return name;
}

int player::getScore()
{
	return score;
}

void player::setName(string input)
{
	name = input;
}

void player::setScore(int input)
{
	score = input;
}
