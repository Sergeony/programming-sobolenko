/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Sobolenko S.
 * @date 30-may-2022
 * @version 0.0.1
 */

#include "lib.h"

void fillDiagonal(int **matrix, int *diagonal)
{
    for (int i = 0; i < COLS_AND_ROWS; i++) {
        *(diagonal + i) = *(*(matrix + i) + i);
    }
}

void bubbleSort(int *diagonal)
{
    for (int i = 0; i < COLS_AND_ROWS; i++) {
        for (int j = 0; j < COLS_AND_ROWS - i - 1; j++) {

            if (*(diagonal + j) > *(diagonal + (j + 1))) {

                int temp = *(diagonal + j);
                *(diagonal + j) = *(diagonal + (j + 1));
                *(diagonal + (j + 1)) = temp;
            }
        }
    }
}
