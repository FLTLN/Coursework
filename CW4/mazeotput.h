#include "mazegen.h"

#ifndef __MAZEOUTPUT_
#define __MAZEOUTPUT_

void output_TXT(char * mazeArray, PAR * par, const char * name);
void output_PNG(char * mazeArray, PAR * par, const char * name);

void output_roads_log(PAR * par);

#endif // !__MAZEOUTPUT_

