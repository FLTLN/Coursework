#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mazegen.h"
#include "mazeotput.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	PAR maze_par;

	maze_par.W = 100;
	maze_par.H = 100;

	maze_par.max_W = 10;
	maze_par.max_H = 10;


	create_Rooms_List(&maze_par); //Create list with rooms courners

	link_Rooms(&maze_par); //Linking rooms with their neihbourhoods

	//createMazeFile(&maze_par, "maze.txt");

	char * mazeArray = create_Maze_Array(&maze_par);


	output_TXT(mazeArray, &maze_par, "maze.txt");
	output_PNG(mazeArray, &maze_par, "test.png");
	output_PNG_HQ(mazeArray, &maze_par, "test_hq.png");

	//printf_s("%d\n", maze_par.rooms_quantity);
	//printf_s("%d\n", maze_par.max_quantity_on_x);
}

