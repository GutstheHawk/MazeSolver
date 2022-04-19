#include "Creature.h"
#include "Maze.h"
using namespace std;



int main()
{
	Maze testmaze{};
	Creature adventurer{12, 6};

	cout << endl;

	adventurer.goNorth(testmaze);

}
