#include <iostream>
#include <iomanip>
#include <string>
#include "Maze.h"
#include "Creature.h"
using namespace std;

ostream& operator<<(ostream& output, Maze& maze)
{
	string mazeBoard;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (maze.getPoint(j, i) == 0)
			{
				mazeBoard = mazeBoard + " ";
			}
			else if (maze.getPoint(j, i) == 1)
			{
				mazeBoard = mazeBoard + "X";
			}
			else if (maze.getPoint(j, i) == 2)
			{
				mazeBoard = mazeBoard + "#";
			}
			else if (maze.getPoint(j, i) == 3)
			{
				mazeBoard = mazeBoard + "S";
			}
			else if (maze.getPoint(j, i) == 4)
			{
				mazeBoard = mazeBoard + "E";
			}
			else if (maze.getPoint(j, i) == 5)
			{
				mazeBoard = mazeBoard + "+";
			}
			else
			{
				cout << "Something went wrong with your array!";
			}
		}
		mazeBoard = mazeBoard + "\n";
	}

	output << mazeBoard << endl;
	return output;

}

Creature::Creature(int x, int y)
{
	X = x;
	Y = y;
	bool success = false;
}

int Creature::getX()
{
	return X;
}

int Creature::getY()
{
	return Y;
}

/*
		cout << "Before value: " << maze.getPoint(X, Y) << endl;
		cout << "New location value: " << maze.getPoint(X, Y) << endl;
		cout << "Location changed: " << maze.getPoint(X, Y) << endl;
		cout << "Y: " << this->getY() << endl;
		cout << "X: " << this->getX() << endl;
*/

bool Creature::goNorth(Maze maze)
{	
	if (maze.getPoint(X, (Y - 1)) == 4)
	{
		cout << maze;
		cout << "Congrats! The maze has been solved!" << endl;
		success = true;
		return success;
	}
	else if (maze.getPoint(X, (Y - 1)) == 0)
	{
		Y = (Y - 1);
		maze.setPoint(X, Y, 2);
		cout << maze;
			success = goNorth(maze);
			if (!success)
			{
				success = goEast(maze);
				if (!success)
				{
					success = goWest(maze);
					if (!success)
					{
						maze.setPoint(X, Y, 5);
						Y = (Y + 1);
						goEast(maze);
					}
				}
			}
	}
	else if (maze.getPoint(X, (Y - 1)) == 2)
	{
		Y = (Y - 1);
		maze.setPoint(X, Y, 5);
		cout << maze;
		goNorth(maze);
	}
	else
	{
		success = false;
		return success;
	}
}

bool Creature::goEast(Maze maze)
{
	if (maze.getPoint((X + 1), Y) == 4)
	{
		cout << maze;
		cout << "Congrats! The maze has been solved!" << endl;
		success = true;
		return success;
	}
	else if (maze.getPoint((X + 1), Y) == 0)
	{
		X = (X + 1);
		maze.setPoint(X, Y, 2);
		cout << maze;
			success = goNorth(maze);
			if (!success)
			{
				success = goEast(maze);
				if (!success)
				{
					success = goSouth(maze);
					if (!success)
					{
						maze.setPoint(X, Y, 5);
						cout << maze;
						X = (X - 1);
						goSouth(maze);
					}
				}
			}
	}
	else if (maze.getPoint((X + 1), Y) == 2)
	{
		X = (X + 1);
		maze.setPoint(X, Y, 5);
		cout << maze;
		goEast(maze);
	}
	else
	{
		success = false;
		return success;
	}
}

bool Creature::goSouth(Maze maze)
{
	if (maze.getPoint(X, Y) == 4)
	{
		cout << maze;
		cout << "Congrats! The maze has been solved!" << endl;
		success = true;
		return success;
	}
	else if (maze.getPoint(X, (Y + 1)) == 0)
	{
		Y = (Y + 1);
		maze.setPoint(X, Y, 2);
		cout << maze;
		if (maze.getPoint(X, Y) == 4)
		{
			success = true;
			return success;
		}
			success = goEast(maze);
			if (!success)
			{
				success = goSouth(maze);
				if (!success)
				{
					success = goWest(maze);
					if (!success)
					{
						maze.setPoint(X, Y, 5);
						cout << maze;
						Y = (Y - 1);
						goNorth(maze);
					}
				}
			}
	}
	else if (maze.getPoint(X, (Y + 1)) == 2)
	{
		Y = (Y + 1);
		maze.setPoint(X, Y, 5);
		cout << maze;
		goSouth(maze);
	}
	else
	{
		success = false;
		return success;
	}
}

bool Creature::goWest(Maze maze)
{
	if (maze.getPoint(X, Y) == 4)
	{
		cout << maze;
		cout << "Congrats! The maze has been solved!" << endl;
		success = true;
		return success;
	}
	else if (maze.getPoint((X - 1), Y) == 0)
	{
		X = (X - 1);
		maze.setPoint(X, Y, 2);
		cout << maze;
			success = goWest(maze);
			if (!success)
			{
				success = goSouth(maze);
				if (!success)
				{
					success = goNorth(maze);
					if (!success)
					{
						maze.setPoint(X, Y, 5);
						cout << maze;
						X = (X + 1);
						goNorth(maze);
					}
				}
			}
	}
	else if (maze.getPoint((X - 1), Y) == 2)
	{
		X = (X - 1);
		maze.setPoint(X, Y, 5);
		cout << maze;
		goWest(maze);
	}
	else
	{
		success = false;
		return success;
	}
}