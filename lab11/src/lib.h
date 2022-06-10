#ifndef __LIB_H__
#define __LIB_H__

/**
 * @file lib.h
 * @brief Файл з вхідними даними та перерахуванням функцій
 *
 * @author Sobolenko S.
 * @date 05-jul-2022
 * @version 0.0.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Кількість рядків матриці
 */
#define ROWS 3

/**
 * Кількість стовпців матриці 
 */
#define COLS 3

/**
 * Функція заповнення матриці
 * 
 * Опис роботи: 
 *  - У вкладеному циклі запрошувати елемент у консолі та перевіряти його на валідність
 *  - Перепрошувати, якщо не валідний(поза діапозоном)
 * @param matrix матриця для заповнювання
 */
void fillMatrix(double **matrix);

/**
 * Функція сумування матриць
 * 
 * Опис роботи:
 *  - У вкладеному циклі поелементно сумувати дві матриці та записувати результат до resultMatrix
 * @param matirx1 ліва матриця
 * @param matrix2 права матриця
 * @param resultMatrix результуюча матриця
 */
void sumMatrices(double **matrix1, double **matrix2, double **resultMatrix);


/**
 * Функція виводу матриці
 * 
 * Опис роботи:
 *  - У вкладеному циклі поелементно виводити матрицю до консолі 
 * @param matirx вхідна матриця
 */
void printMatrix(double **matrix);

#endif
