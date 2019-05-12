#include "pathfinder.h"
#include "mazegen.h"
#include <stdio.h>
#include <malloc.h>

void find_path(ROAD_NODE ** path,PAR * where, int from, int to,int refresh)
{

	if (refresh)
	{
		ROAD_NODE * new_waypoint = (ROAD_NODE *)malloc(sizeof(ROAD_NODE));

		new_waypoint->unvisited_U = 1;
		new_waypoint->unvisited_B = 1;
		new_waypoint->unvisited_R = 1;
		new_waypoint->unvisited_L = 1;

		ROOM * current_room = findRoom(where->rooms_courners_list, from);

		printf_s("on %d\n", current_room->number);

		new_waypoint->room = current_room;
		new_waypoint->prev_room = *path;
		*path = new_waypoint;
	}

	if (from == to) return;
	else
	{

		if ((*path)->unvisited_U && (*path)->room->UN_R && findRoom(where->rooms_courners_list, (*path)->room->UN_N)->not_wisited)
		{
			(*path)->unvisited_U = 0;
			(*path)->room->not_wisited = 0;
			find_path(path, where, (*path)->room->UN_N, to,1);
		}
		else if ((*path)->unvisited_B && (*path)->room->BN_R && findRoom(where->rooms_courners_list, (*path)->room->BN_N)->not_wisited)
		{
			(*path)->unvisited_B = 0;
			(*path)->room->not_wisited = 0;
			find_path(path, where, (*path)->room->BN_N, to,1);
		}
		else if ((*path)->unvisited_R && (*path)->room->RN_R && findRoom(where->rooms_courners_list, (*path)->room->RN_N)->not_wisited)
		{
			(*path)->unvisited_R = 0;
			(*path)->room->not_wisited = 0;
			find_path(path, where, (*path)->room->RN_N, to,1);
		}
		else if ((*path)->unvisited_L && (*path)->room->LN_R && findRoom(where->rooms_courners_list, (*path)->room->LN_N)->not_wisited)
		{
			(*path)->unvisited_L = 0;
			(*path)->room->not_wisited = 0;
			find_path(path, where, (*path)->room->LN_N, to,1);
		}
		else
		{
			//(*path)->room->is_false_road = 1;
			findRoom(where->rooms_courners_list, (*path)->room->number)->is_false_road = 1;
			ROAD_NODE * free_me = (*path);
			(*path) = (*path)->prev_room;
			free(free_me);
			find_path(path, where, (*path)->room->number, to,0);
		}
	}
}

void printPath(ROAD_NODE * path_pointer)
{
	ROAD_NODE * path = path_pointer;

	if (path)
	{
		printf_s("%d ", path->room->number);

		while (path)
		{
			printf_s("<- %d ", path->room->number);

			path = path->prev_room;
		}
	}


}

void link_Path(ROAD_NODE * path_in)
{
	ROAD_NODE * path = path_in;
	while (path)
	{
		path->room->is_road = 1;

		path = path->prev_room;
	}
}