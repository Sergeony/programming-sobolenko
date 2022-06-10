/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Sobolenko S.
 * @date 05-jul-2022
 * @version 0.0.1
 */

#include "lib.h"

double convertToNumber(const char *string) {
    char terminatedChar = '\0';
    double number = 0;
    bool afterPoint = false;
    double place = 1;

    for (int i = 0; *(string + i) != '\n' && *(string + i) != '\0'; i++) {
        if (*(string + i) == '.') {
            afterPoint = true;
            continue;
        }

        int digit = *(string + i) - '0';

        if (afterPoint) {
            place /= 10;
            number += digit * place;
        } else {
            number *= 10;
            number += digit;
        }
    }

    return number;
}