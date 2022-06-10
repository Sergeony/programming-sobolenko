/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій
 * 
 * @author Sobolenko S.
 * @version 0.0.1
 * @date 30-may-2022
 */

#include "../src/lib.h"
#include "check.h"

/**
 * Верифікація роботи функцій {@link fillDiagonal}, {@link bubbleSort}
 * на основі набора масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(diagonal_test)
{
	int **matrix = (int**)malloc(COLS_AND_ROWS * sizeof(int*));
	for (int i = 0; i < COLS_AND_ROWS; i++) {
		*(matrix + i) = (int*)malloc(COLS_AND_ROWS * sizeof(int));
	}

	for (int i = 0, k = 9; i < COLS_AND_ROWS; i++) {
		for (int j = 0; j < COLS_AND_ROWS; j++, k--) {
			*(*(matrix + i) + j) = k;
		}
	}

	int *diagonal = (int*)malloc(COLS_AND_ROWS * sizeof(int));

    fillDiagonal(matrix, diagonal);
    bubbleSort(diagonal);

    int expected[COLS_AND_ROWS] = {1, 5, 9};

    for(int i=0; i < COLS_AND_ROWS; i++) {
        int actual = *(diagonal + i);
        ck_assert_int_eq(actual, expected[i]);
    }

	for (int i = 0; i < COLS_AND_ROWS; i++) {
		free(*(matrix + i));
	}
	free(matrix);
	free(diagonal);
    matrix = NULL;
    diagonal = NULL;
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
    TCase *tc_core = tcase_create("Lab10");

    tcase_add_test(tc_core, diagonal_test);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
