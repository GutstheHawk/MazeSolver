#pragma once
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Maze
{
private:
	static const int num_rows = 7;

	static const int num_columns = 20;

	int maze[num_columns][num_rows];

public:

	Maze();

	Maze(int, int);

	void drawMaze();

	int getPoint(int, int);

	void setPoint(int, int, int);


};