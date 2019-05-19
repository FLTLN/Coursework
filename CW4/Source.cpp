#include "destroy.h"
#include "user.h"
#include "maze.h"

void main()
{
	PAR maze_par;

	set_default(&maze_par);
	set_user_preferenses(&maze_par);

	create(&maze_par);

	if (is_print_common()) output(&maze_par, "common.png");

	if (is_print_solved())
	{
		solve(&maze_par);
		output(&maze_par, "solved.png");
	}

	stats(&maze_par);

	destroy_maze(&maze_par);
}

