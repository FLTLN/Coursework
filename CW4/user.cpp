#include "user.h"
#include "mazegen.h"
#include <stdio.h>


void set_user_preferenses(PAR * par)
{
	printf_s("Hello!\n");
	printf_s("I am a maze generator\n");
	printf_s("Please type maze size\n RECOMENDATION: less than 1000 or equal\n");
	scanf_s("%d", &(par->H));
	par->W = par->H;

	printf_s("Please type room maximal horizontal size\n NOTISE: Strictly more than 3\n");
	scanf_s("%d", &(par->max_W));

	printf_s("Please type room maximal vertical size\n NOTISE: Strictly more than 3\n");
	scanf_s("%d", &(par->max_H));

	printf_s("Do you want see just a maze? Or solVed maze? Or both?\n");
	printf_s("1 - COMMON\n");
	printf_s("2 - SOLVED\n");
	printf_s("3 - BOTH\n");

	int choose;

	scanf_s("%d", &choose);
	print_common = 0;
	print_solved = 0;

	if (choose == 1) print_common = 1;
	if (choose == 2) print_solved = 1;
	if (choose == 3)
	{
		print_common = 1;
		print_solved = 1;
	}

	printf_s("So, let's generate\n");
	printf_s("Lower you can see some kind of log\n\n");
}

int is_print_common()
{
	return print_common;
}

int is_print_solved()
{
	return print_solved;
}


