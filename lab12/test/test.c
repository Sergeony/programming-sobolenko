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
 * на основі набора вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(convert_to_number_test)
{
	char *string = (char *)malloc(BUFFER_SIZE * sizeof(char));
    fgets(string, BUFFER_SIZE, stdin);

    double expected = 11111.111;
    double actual = convertToNumber(string);

    ck_assert_int_eq(actual, expected);

    free(string);
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
    TCase *tc_core = tcase_create("Lab12");

    tcase_add_test(tc_core, convert_to_number_test);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
