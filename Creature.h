#pragma once
#include <string>
#include "Maze.h"
using namespace std;

class Creature
{
public:
	int X, Y;
	bool success;

	Creature(int, int);

	int getX();

	int getY();

	bool goNorth(Maze);

	bool goEast(Maze);

	bool goSouth(Maze);

	bool goWest(Maze);
};