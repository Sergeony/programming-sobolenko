/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Sobolenko S.
 * @date 05-jul-2022
 * @version 0.0.1
 */

#include "lib.h"

void readFromFile(FILE *f, 
                    int *amplitude, 
                    int *period,
                    char *placeholder)
{
    if (f != NULL) {
		fscanf(f, "%d %d %c", amplitude, period, placeholder);
	} else {
		exit(1);
	}
}

void writeToFile(FILE *f, 
                 char **data,
                 unsigned int height,
                 unsigned int length)
{
    for (unsigned int i = 0; i < height; i++) {
		for (unsigned int j = 0; j < length; j++) {
			fprintf(f, "%c", *(*(data + i) + j));
		}
		fprintf(f, "%c", '\n');
	}
}

void drawData(int amplitude, 
              int period,
              char placeholder,
              char **data,
              unsigned int height,
              unsigned int length)
{
    for (unsigned int i = 0; i < height; i++) {
		for (unsigned int j = 0; j < length; j++) {
			*(*(data + i) + j) = ' ';
		}
	}

    for (int x = 0, y; x < period; x++) {
        y = -(int)round((amplitude * sin(x * PI / (period / 2)))) + amplitude;

        *(*(data + y) + x) = placeholder;
    }
}

void printData()
{
    system("cat ./dist/output.txt");
}