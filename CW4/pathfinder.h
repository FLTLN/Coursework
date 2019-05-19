#ifndef _PATHFINDER__
#define _PATHFINDER__

#include "mazegen.h"

typedef struct road_node
{
	ROOM * room;
	road_node * prev_room; 

	unsigned char unvisited_U : 1;
	unsigned char unvisited_B : 1;
	unsigned char unvisited_L : 1;
	unsigned char unvisited_R : 1;

}ROAD_NODE;

void find_path(ROAD_NODE ** path, PAR * where, int from, int to, int refresh);
void print_path(ROAD_NODE * path_pointer);
void create_path(ROAD_NODE * path_in);


#endif // !_PATHFINDER__
