#include "maze.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void set_default(PAR * par)
{
	par->W = 1000;
	par->H = 1000;

	par->max_W = 50;
	par->max_H = 50;
}

void create(PAR * par)
{
	long int start, stop;

	srand(time(NULL));

	start = clock();

	create_rooms_list(par);
	printf_s("Rooms created\n");

	link_rooms(par);
	printf_s("Rooms linked\n");

	create_roads_map(par);
	printf_s("Roads mapped\n");
	create_roads(par);
	printf_s("Roads created\n");

	stop = clock();

	printf_s("Generated in %f seconds\n", float(stop - start) / CLOCKS_PER_SEC);
}

void solve(PAR * par)
{
	printf_s("Solving start \n");

	long int start, stop;

	start = clock();

	ROAD_NODE * path = NULL;
	find_path(&path, par, 1, par->rooms_quantity, 1);
	create_path(path);
	destroy_path(path);

	stop = clock();

	printf_s("Solved in %f seconds\n", float(stop - start) / CLOCKS_PER_SEC);
}

void output(PAR * par,const char * name)
{
	char * mazeArray = create_maze_array(par);
	output_PNG(mazeArray, par, name);
	free(mazeArray);
}

void stats(PAR * par)
{
	printf_s("Maze parametres:\n");
	printf_s("Maze size - %d X %d tiles\n", par->W, par->H);
	printf_s("Rooms quantity - %d\n", par->rooms_quantity);
}