#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mazegen.h"
#include "mazeotput.h"
#include "pathfinder.h"
#include "destroy.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	PAR maze_par;

	maze_par.W = 1000;
	maze_par.H = 1000;


	maze_par.max_W = 50;
	maze_par.max_H = 50;


	create_Rooms_List(&maze_par); //Create list with rooms courners

	link_Rooms(&maze_par); //Linking rooms with their neihbourhoods

	ROAD_NODE * path = NULL;

	createRoadsMap(&maze_par);
	outputRoadsLog(&maze_par);
	find_path(&path, &maze_par, 1, maze_par.rooms_quantity, 1);
	printPath(path);

	createPathes(&maze_par);
	link_Path(path);

	char * mazeArray = create_Maze_Array(&maze_par);


	//output_TXT(mazeArray, &maze_par, "maze.txt");
	output_PNG(mazeArray, &maze_par, "rooms.png");

	destroy_maze(&maze_par);

}

