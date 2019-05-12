#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mazegen.h"
#include "mazeotput.h"
#include "pathfinder.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	PAR maze_par;

	maze_par.W = 40;
	maze_par.H = 55;

	maze_par.max_W = 15;
	maze_par.max_H = 15;


	create_Rooms_List(&maze_par); //Create list with rooms courners

	link_Rooms(&maze_par); //Linking rooms with their neihbourhoods

	ROAD_NODE * path = NULL;

	createRoadsMap(&maze_par);
	outputRoadsLog(&maze_par);
	find_path(&path, &maze_par, 1, 6, 1);
	printPath(path);

	createPathes(&maze_par);


	char * mazeArray = create_Maze_Array(&maze_par);


	output_TXT(mazeArray, &maze_par, "maze.txt");

}

