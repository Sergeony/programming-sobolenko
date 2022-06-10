/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій
 * 
 * @author Sobolenko S.
 * @version 0.0.1
 * @date 15-feb-2022
 */

#include "../src/lib.h"
#include "check.h"

/**
 * Верифікація роботи функції {@link getWordsCount}
 * на основі набора масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(test_get_words_count)
{
    #define STRING_COUNT 3

    char inputData[][TEXT_LEN] = { " a b c d", 
                                   "abcde fg",
                                   "   aaaaa" };
    int expected[] = {4, 2, 1};

    for (int i = 0; i < STRING_COUNT; i++) {
        int actual = getWordsCount(inputData[i], TEXT_LEN);
        ck_assert_int_eq(actual, expected[i]);
    }
}
END_TEST

/**
 * Верифікація роботи функції {@link isNumberGreat}
 * на основі набора масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(test_is_number_great)
{
    #define NUM_COUNT 4

    int inputData[] = {6, 2, 1, 4};
    bool expected[] = {true, false, true, false};

    for (int i = 0; i < NUM_COUNT; i++) {
        int actual = isNumberGreat(inputData[i]);
        ck_assert_int_eq(actual, expected[i]);
    }
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
    TCase *tc_core = tcase_create("Lab09");

    tcase_add_test(tc_core, test_get_words_count);
    tcase_add_test(tc_core, test_is_number_great);
    suite_add_tcase(s, tc_core);
    
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
