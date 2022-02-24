/**
 * @file lib.h
 * Header file of functions for lab09.
 * @author sergey_sobolenko
 * @version 0.0.1
 * @date 15.02.2022
 */
#ifndef __LIB_H__
#define __LIB_H__
#include <stdbool.h>

/**
 *Counts the number of words in a string.
 *@param string[] text for counts
 *@param string_len text length
 *@return words count
 */
int get_words_count(char string[], int string_len);

/**
 *Checks if a number is equal to the sum of its divisors.
 *@param number to check
 *@return is number great
 */
bool is_number_great(int number);

#endif
