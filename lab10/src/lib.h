#ifndef __LIB_H__
#define __LIB_H__

/**
 * @file lib.h
 * @brief Файл з вхідними даними та перерахуванням функцій
 *
 * @author Sobolenko S.
 * @date 30-may-2022
 * @version 0.0.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Розмір квадратної вхідної матриці
 */
#define COLS_AND_ROWS 3

/**
 * Функція заповнення діагоналі
 * 
 * Опис роботи: 
 *  - Заповнює масив елементами в яких рядок дорівнює стовбцю.
 * @param matrix pointer on matrix
 * @param diagonal pointer on diagonal
 */
void fillDiagonal(int **matrix, int *diagonal);

/**
 * Функція сортування
 * 
 * Опис роботи:
 *  - Сортує звичайним бульбашковим алгоритмом за зростанням.
 * @param diagonal pointer on matrix
 */
void bubbleSort(int *diagonal);

#endif
