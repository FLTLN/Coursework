#ifndef __MAZE_
#define __MAZE_

#include "mazegen.h"
#include "mazeotput.h"
#include "pathfinder.h"
#include "destroy.h"
#include "user.h"

void set_default(PAR * par);
void create(PAR * par);
void solve(PAR * par);
void output(PAR * par, const char * name);
void stats(PAR * par);

#endif // !__MAZE_

