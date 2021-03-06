#define _CRT_SECURE_NO_WARNINGS
#define SYMBOL_SIZE 10
#include "mazeotput.h"
#include "mazegen.h"
#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include <zlib.h>

void output_TXT(char * mazeArray, PAR * par, const char * name)
{
	int i, j;
	char newline[] = { "\n" };
	FILE * file = fopen(name, "w");

	if (file)
	{
		for (i = 0; i < par->W; i++)
		{
			for (j = 0; j < par->H; j++)
			{
				fputc(*(mazeArray + (i* par->H) + j), file);
			}
			fputs(newline, file);
		}
	}
} //This function was used for test

void output_PNG(char * mazeArray, PAR * par, const char * name)
{
	FILE *fp = fopen(name, "wb");
	if (!fp) {
		return;
	}

	png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);

	if (!png_ptr) {
		fclose(fp);
		return;
	}

	png_infop png_info;
	png_info = png_create_info_struct(png_ptr);
	png_init_io(png_ptr, fp);

	png_set_IHDR(png_ptr, png_info, par->H, par->W, 8, PNG_COLOR_TYPE_RGB,
		PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
		PNG_FILTER_TYPE_DEFAULT);

	unsigned char **rows = (unsigned char **)malloc(par->W * sizeof(unsigned char *));

	unsigned char *data = (unsigned char *)malloc(par->H * par->W * 3 * sizeof(unsigned char));
	char * mazeArrayFlipped = (char *)malloc(par->H * par->W * sizeof(char));

	int i = 0;
	int j = 0;

	for (i = 0; i < par->H; i++)
	{
		for (j = 0; j < par->W; j++)
		{
			*(mazeArrayFlipped + i * par->W + j) = *(mazeArray + (par->H - i) * par->W + j);
		}
	}

	mazeArray = mazeArrayFlipped;

	for (i = 0; i < par->H * par->W * 3; i = i + 3)
	{
		*(data + i) = 0;
		*(data + i + 1) = 0;
		*(data + i + 2) = 0;

		if (mazeArray[j] != '#')
		{
			*(data + i) = 255;
			*(data + i + 1) = 255;
			*(data + i + 2) = 255;
		}

		if (mazeArray[j] == '+')
		{
			*(data + i) = 255;
			*(data + i + 1) = 100;
			*(data + i + 2) = 100;
		}
		if (mazeArray[j] == 'F')
		{
			*(data + i) = 100;
			*(data + i + 1) = 100;
			*(data + i + 2) = 255;
		}

		j++;
	}


	for (i = par->H; i >= 0; i--)
	{
		rows[par->W - i - 1] = data + (i * par->W * 3);
	}

	png_set_rows(png_ptr, png_info, rows);
	png_write_png(png_ptr, png_info, PNG_TRANSFORM_IDENTITY, nullptr);
	png_write_end(png_ptr, png_info);

	free(mazeArrayFlipped);
	fclose(fp);
}

void output_roads_log(PAR * par)
{
	ROOM * rooms = par->rooms_courners_list;

	while (rooms)
	{
		printf_s("ROOM NUMBER %d HAS ROADS WITH\n", rooms->number);

		if (rooms->BN_R)
		{
			printf_s(" ROOM %d  B\n\n", rooms->BN_N);
		}
		if (rooms->UN_R)
		{
			printf_s(" ROOM %d  U\n\n", rooms->UN_N);
		}
		if (rooms->LN_R)
		{
			printf_s(" ROOM %d  L\n\n", rooms->LN_N);
		}
		if (rooms->RN_R)
		{
			printf_s(" ROOM %d  R\n\n", rooms->RN_N);
		}
	
		rooms = rooms->next_room;
	}
}
