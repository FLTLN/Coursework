#include "destroy.h"
#include <malloc.h>
#include <stdio.h>

void destroy_roads(POINT * road)
{
	if (road)
	{
		destroy_roads(road->next_point);
		free(road);
	}
}

void destroy_rooms(ROOM * room)
{
	if (room)
	{
		destroy_rooms(room->next_room);
		free(room);
	}
}

void destroy_maze(PAR * maze)
{
	ROOM * rooms = maze->rooms_courners_list;

	while (rooms)
	{

		if (rooms->U_road)
		{
			destroy_roads(rooms->U_road);
		}

		if (rooms->B_road)
		{
			destroy_roads(rooms->B_road);
		}

		if (rooms->L_road)
		{
			destroy_roads(rooms->L_road);
		}

		if (rooms->R_road)
		{
			destroy_roads(rooms->R_road);
		}

		rooms = rooms->next_room;
	}

	destroy_rooms(maze->rooms_courners_list);
}

void destroy_path(ROAD_NODE * room)
{
	if (room)
	{
		destroy_path(room->prev_room);
		free(room);
	}
}