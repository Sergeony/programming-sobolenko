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
#include <stdbool.h>

/**
 * Кількість символів
 */
#define BUFFER_SIZE 1000

/**
 * Функція конвертації у число
 * 
 * Опис роботи: 
 *  - Доки не зустріниться точка, помножати результат на 10 та додавати нову цифру
 *  - Після того як зустрілась точка, кожну цифру ділити на 10 у ступені порядка цифри після точки
 *  та додавати до результату
 * @param string число у вигляді строки
 * @return конвертоване число
 */
double convertToNumber(const char *string);

#endif
