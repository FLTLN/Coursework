#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mazegen.h"
#include "mazeotput.h"
#include "pathfinder.h"
#include "destroy.h"
#include "user.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	PAR maze_par;

	maze_par.W = 1000;
	maze_par.H = 1000;


	maze_par.max_W = 50;
	maze_par.max_H = 50;

	set_user_preferenses(&maze_par);

	create_Rooms_List(&maze_par); //Create list with rooms courners

	link_Rooms(&maze_par); //Linking rooms with their neihbourhoods

	ROAD_NODE * path = NULL;

	createRoadsMap(&maze_par);
	outputRoadsLog(&maze_par);
	createPathes(&maze_par);
	char * mazeArray = create_Maze_Array(&maze_par);
	if(is_print_common) output_PNG(mazeArray, &maze_par, "common.png");

	if (is_print_solved)
	{
		find_path(&path, &maze_par, 1, maze_par.rooms_quantity, 1);
		printPath(path);
		link_Path(path);

		char * mazeArray = create_Maze_Array(&maze_par);
		output_PNG(mazeArray, &maze_par, "solved.png");
	}

	destroy_maze(&maze_par);

}

