#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Maze.h"
#include "Creature.h"
using namespace std;

Maze::Maze()
{
	for (int j = 0; j < 7; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			maze[i][j] = { 1 };
		}
	}

	/*

	for (int i = 0; i < 20; i++)
	{
		board[i][0] = { 1 };
	}

	for (int i = 0; i < 20; i++)
	{
		board[i][6] = { 1 };
	}

	for (int j = 0; j < 7; j++)
	{
		board[0][j] = { 1 };
	}

	for (int j = 0; j < 7; j++)
	{
		board[19][j] = { 1 };
	}

	*/

	for (int i = 1; i < 15; i++)
	{
		if (i == 6)
		{
			i++;
		}

		maze[i][1] = { 0 };
	}

	for (int i = 3; i < 13; i++)
	{
		maze[i][4] = { 0 };
	}

	for (int j = 1; j < 6; j++)
	{
		maze[1][j] = { 0 };
	}

	for (int j = 1; j < 5; j++)
	{
		maze[7][j] = { 0 };
	}

	for (int j = 4; j < 7; j++)
	{
		maze[12][j] = { 0 };
	}

	for (int j = 2; j < 6; j++)
	{
		maze[15][j] = { 0 };
	}

	for (int j = 0; j < 6; j++)
	{
		maze[18][j] = { 0 };
	}

	maze[8][2] = { 0 };

	maze[14][2] = { 0 };
	maze[15][2] = { 0 };

	maze[16][5] = { 0 };
	maze[17][5] = { 0 };

	maze[12][6] = { 3 };
	maze[18][0] = { 4 };
}

int Maze::getPoint(int x, int y)
{
	int contents = maze[x][y];
	return contents;
}

void Maze::setPoint(int x, int y, int value)
{
	maze[x][y] = value;
}

/*

void Maze::drawMaze()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (maze[j][i] == 0)
			{
				cout << " ";
			}
			else if (maze[j][i] == 1)
			{
				cout << "X";
			}
			else if (maze[j][i] == 2)
			{
				cout << "#";
			}
			else if (maze[j][i] == 3)
			{
				cout << "S";
			}
			else if (maze[j][i] == 4)
			{
				cout << "E";
			}
			else if (maze[j][i] == 5)
			{
				cout << "+";
			}
			else
			{
				cout << "Something went wrong with your array!";
			}
		}
		cout << endl;
	}
	cout << endl;
}

*/