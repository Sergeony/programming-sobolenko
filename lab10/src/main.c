/**
 * @file main.c
 * @brief Файл з демонстрацією виконаноії роботи
 *
 * @author Sobolenko S.
 * @version 0.0.1
 * @date 30-may-2022
 */

#include "lib.h"

/**
 * Основна функція
 * 
 * Опис роботи: 
 * - Створюємо двовимірний масив matrix.
 * - Заповнюємо його випадковими значеннями.
 * - Створюємо вихідний масив diagonal.
 * - Заповнюємо його елементами на головній діагоналі.
 * - Сортуємо за зростанням.- Звільняємо пам'ять.
 * @return успішний код повернення з програми (0)
 */
int main(void)
{
	time_t t;
	srand((unsigned) time(&t));

	int **matrix = (int**) malloc(COLS_AND_ROWS * sizeof(int*));
	for (int i = 0; i < COLS_AND_ROWS; i++) {
		*(matrix + i) = (int*) malloc(COLS_AND_ROWS * sizeof(int));
	}

	for (int i = 0; i < COLS_AND_ROWS; i++) {
		for (int j = 0; j < COLS_AND_ROWS; j++) {
			*(*(matrix + i) + j) = rand() % 10;
		}
	}

	int *diagonal = (int*)malloc(COLS_AND_ROWS * sizeof(int));

    fillDiagonal(matrix, diagonal);

    bubbleSort(diagonal);

	for (int i = 0; i < COLS_AND_ROWS; i++) {
		free(*(matrix + i));
	}
	free(matrix);
	free(diagonal);
    matrix = NULL;
    diagonal = NULL;

	return 0;
}
