#define _CRT_SECURE_NO_WARNINGS
#define SYMBOL_SIZE 40
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
}

void output_PNG(char * mazeArray, PAR * par, const char * name)
{
	FILE *fp = fopen("new.png", "wb");
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

	//unsigned char *rows[200];
	unsigned char **rows = (unsigned char **)malloc(par->W * sizeof(unsigned char *));

	//unsigned char data[200 * 200 * 3];
	unsigned char *data = (unsigned char *)malloc(par->H * par->W * 3 * sizeof(unsigned char));
	char * mazeArrayFlipped = (char *)malloc(par->H * par->W * sizeof(char));

	//if (mazeArrayFlipped) printf_s("LLLOLLLOLL\n");


	int i = 0;
	//int j = par->H * par->W;
	int j = 0;

	for (i = 0; i < par->H; i++)
	{
		for (j = 0; j < par->W; j++)
		{
			//printf_s("%d %d -- %d\n",i,j, par->W);
			*(mazeArrayFlipped + i * par->W + j) = *(mazeArray + (par->H - i) * par->W + j);
		}
	}

	mazeArray = mazeArrayFlipped;

	for (i = 0; i < par->H * par->W * 3; i = i + 3)
	{
		*(data + i) = 0;
		*(data + i + 1) = 0;
		*(data + i + 2) = 0;

		//printf_s("%c\n", mazeArray[i / 3]);

		if (mazeArray[j] != '#')
		{
			*(data + i) = 255;
			*(data + i + 1) = 255;
			*(data + i + 2) = 255;
		}
		j++;
	}


	for (i = par->H; i >= 0; i--)
	{
		rows[par->W - i - 1] = data + (i * par->W * 3);
	}

	//rows[height - i - 1] = data + (i*width * 3);

	png_set_rows(png_ptr, png_info, rows);
	png_write_png(png_ptr, png_info, PNG_TRANSFORM_IDENTITY, nullptr);
	png_write_end(png_ptr, png_info);


	fclose(fp);
}

void output_PNG_HQ(char * mazeArray, PAR * par, const char * name)
{
	
}
