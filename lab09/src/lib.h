#ifndef __LIB_H__
#define __LIB_H__

/**
 * @file lib.h
 * @brief Файл з вхідними даними та перерахуванням функцій
 * 
 * @author Sobolenko S.
 * @version 0.0.1
 * @date 15-feb-2022
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Довжина тексту
 */
#define TEXT_LEN 9

/**
 * Функція кількості слів у тексті
 * 
 * Опис роботи:
 * - Якщо 1-ий символ слова не пробіл, то рахуємо як 1-ше слово
 * - У циклі, починаючи с 2-ого елемента перевіряю чи є даний символ НЕ пробілом, 
 *   а попередній пробілом. Якщо так, то рахую слово
 * 
 * @param string[] вхідний текст
 * @param stringLen довжина тексту
 * 
 * @return words count
 */
int getWordsCount(char string[], int stringLen);

/**
 * Функція досконалого числа
 * 
 * Опис роботи:
 * - Якщо слово дорівнює сумі своїх дільників, то воно досконале
 * 
 * @param number вхідне число
 * 
 * @return чи є число досконалим
 */
bool isNumberGreat(int number);

#endif
