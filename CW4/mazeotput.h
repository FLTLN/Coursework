#include "mazegen.h"

#ifndef __MAZEOUTPUT_
#define __MAZEOUTPUT_

void output_TXT(char * mazeArray, PAR * par, const char * name);
void output_PNG(char * mazeArray, PAR * par, const char * name);
void output_PNG_HQ(char * mazeArray, PAR * par, const char * name);

void outputRoadsLog(PAR * par);

#endif // !__MAZEOUTPUT_

