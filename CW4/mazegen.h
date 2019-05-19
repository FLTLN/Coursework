#ifndef __MAZEGEN_
#define __MAZEGEN_

typedef struct point
{
	unsigned int x;
	unsigned int y;

	point * next_point;

}POINT;

typedef struct room
{
	POINT up_courner;
	POINT down_courner;

	unsigned int number = 0;

	unsigned int UN_N = 0;
	unsigned int BN_N = 0;
	unsigned int LN_N = 0;
	unsigned int RN_N = 0;

	unsigned char UN_R:1;
	unsigned char BN_R:1;
	unsigned char LN_R:1;
	unsigned char RN_R:1;

	POINT * U_road;
	POINT * B_road;
	POINT * L_road;
	POINT * R_road;

	unsigned int with_road:1;
	unsigned int not_wisited:1;
	unsigned int is_road : 1;
	unsigned int is_false_road : 1;

	room * next_room;

}ROOM;

typedef struct par
{
	unsigned int H;
	unsigned int W;

	unsigned int max_H;
	unsigned int max_W;

	unsigned int rooms_quantity = 0;

	unsigned int max_quantity_on_x;

	ROOM * rooms_courners_list;

}PAR;

void link_rooms(PAR * par);
ROOM * find_room(ROOM * rooms, unsigned int number);
void create_roads_map(PAR * where);
void create_roads(PAR * where_in);
void create_rooms_list(PAR * par); 
char * create_maze_array(PAR * par);

#endif // !__MAZEGEN_


