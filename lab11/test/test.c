/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій
 * 
 * @author Sobolenko S.
 * @version 0.0.1
 * @date 05-jul-2022
 */

#include "../src/lib.h"
#include "check.h"

/**
 * Верифікація роботи функцій
 * на основі набора масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(sum_matrices_test)
{
	double **matrix1 = (double **)malloc(ROWS * sizeof(double *));
	double **matrix2 = (double **)malloc(ROWS * sizeof(double *));
	double **resultMatrix = (double **)malloc(ROWS * sizeof(double *));

	for (int i = 0; i < ROWS; i++) {
		*(matrix1 + i) = (double *)malloc(COLS * sizeof(double));
		*(matrix2 + i) = (double *)malloc(COLS * sizeof(double));
		*(resultMatrix + i) = (double *)malloc(COLS * sizeof(double)); 
	}

    for (int i = 0, value = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++, value++) {
            *(*(matrix1 + i) + j) = value;
            *(*(matrix2 + i) + j) = value;
        }
    }

    double expectedResultMatrix[ROWS][COLS] = {
        {0, 2, 4},
        {6, 8, 10},
        {12, 14, 16}
    };

    sumMatrices(matrix1, matrix2, resultMatrix);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            double actual = *(*(resultMatrix + i) + j);
            ck_assert_int_eq(actual, expectedResultMatrix[i][j]);
        }
    }

	for (int i = 0; i < ROWS; i++) {
		free(*(matrix1 + i));
		free(*(matrix2 + i));
		free(*(resultMatrix + i));
	}
	free(matrix1);
	free(matrix2);
	free(resultMatrix);
	matrix1 = matrix2 = resultMatrix = NULL;
}
END_TEST

/**
 * Точка входу модуля тестування
 *
 * Опис роботи:
 *  - Запускає розроблені функції
 *  - По завершенню тестів виводиться на екран резуміюча інформація про стан 
 *    проходження тестів.
 * 
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
int main(void)
{
    Suite *s = suite_create("Programming");
    TCase *tc_core = tcase_create("Lab11");

    tcase_add_test(tc_core, sum_matrices_test);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
