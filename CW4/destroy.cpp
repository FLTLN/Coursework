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
	printf_s("<DES> START\n");

	ROOM * rooms = maze->rooms_courners_list;

	while (rooms)
	{

		if (rooms->U_road)
		{
			destroy_roads(rooms->U_road);
			printf_s("<DES> ROOM %d U ROAD DESTROYED\n", rooms->number);
		}

		if (rooms->B_road)
		{
			destroy_roads(rooms->B_road);
			printf_s("<DES> ROOM %d B ROAD DESTROYED\n", rooms->number);
		}

		if (rooms->L_road)
		{
			destroy_roads(rooms->L_road);
			printf_s("<DES> ROOM %d L ROAD DESTROYED\n", rooms->number);
		}

		if (rooms->R_road)
		{
			destroy_roads(rooms->R_road);
			printf_s("<DES> ROOM %d R ROAD DESTROYED\n", rooms->number);
		}

		rooms = rooms->next_room;
	}

	destroy_rooms(maze->rooms_courners_list);

	printf_s("<DES> DONE\n");
}