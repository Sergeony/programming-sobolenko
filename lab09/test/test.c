#include "../src/lib.h"
#include <stdlib.h>
#include <stdbool.h>
#include <check.h>


START_TEST(test_get_words_count)
{
    #define TEXT_LEN 7
    char text[TEXT_LEN] = {' ', 'a', ' ', 'b', ' ', 'c', 'd'};
    int expected = 4;
    int actual = get_words_count(text, TEXT_LEN);
    ch_assert_int_eq(actual, expected);
}
END_TEST


START_TEST(test_is_number_great)
{
    int num = 6;
    bool expected = true;
    int actual = is_number_great(num);
    ch_assert_int_eq(actual, expected);
}
END_TEST


int main(void)
{
    Suite *s = suite_create("Programming");
    TCase *tc_core = tcase_create("Lab09");
    
    tcase_add_tcase(s, tc_core);
    
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = sunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
