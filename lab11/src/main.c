/**
 * @file main.c
 * @brief Файл з демонстрацією виконаноії роботи
 *
 * @author Sobolenko S.
 * @version 0.0.1
 * @date 05-jul-2022
 */

#include "lib.h"

/**
 * Основна функція
 * 
 * Опис роботи: 
 * - Створюємо першу, другу та результуючу матрицію
 * - Заповнюємо першу та другу матриці
 * - Розраховуємо результуючу матрицю
 * - Виводимо вхідні та вихідну матриці
 * @return успішний код повернення з програми (0)
 */
int main(void)
{
	printf("\nСоболенко Сергій КН-921б. Лабораторна робота No11. Взаємодія з користувачем шляхом механізму введення/виведення\n");

	double **matrix1 = (double **)malloc(ROWS * sizeof(double *));
	double **matrix2 = (double **)malloc(ROWS * sizeof(double *));
	double **resultMatrix = (double **)malloc(ROWS * sizeof(double *));

	for (int i = 0; i < COLS; i++) {
		*(matrix1 + i) = (double *)malloc(COLS * sizeof(double));
		*(matrix2 + i) = (double *)malloc(COLS * sizeof(double));
		*(resultMatrix + i) = (double *)malloc(COLS * sizeof(double)); 
	}

	printf("\nFill the first matrix:");
	fillMatrix(matrix1);

	printf("\nFill the second matrix:");
	fillMatrix(matrix2);

	sumMatrices(matrix1, matrix2, resultMatrix);

	printf("\nThe first matrix:\n");
	printMatrix(matrix1);
	
	printf("\nThe second matrix:\n");
	printMatrix(matrix2);

	printf("\nThe result matrix:\n");
	printMatrix(resultMatrix);

	for (int i = 0; i < COLS; i++) {
		free(*(matrix1 + i));
		free(*(matrix2 + i));
		free(*(resultMatrix + i));
	}
	free(matrix1);
	free(matrix2);
	free(resultMatrix);
	matrix1 = matrix2 = resultMatrix = NULL;

	return 0;
}
