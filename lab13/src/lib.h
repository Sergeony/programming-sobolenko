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
#include <math.h>
#include <stdlib.h>

/**
 * Математична константа пі
 */
#define PI 3.14159

/**
 * Функція зчитування початкових даних з файлу
 * 
 * Опис роботи: 
 *  - Перевірити файл на вмістимість
 *  - Зчитати три змінних
 *  - Закрити файл
 * @param f об'єкт файлу
 * @param amplitude амплітуда функції
 * @param period період функції
 * @param placeholder символ заповнювач
 */
void readFromFile(FILE *f, 
                  int *amplitude, 
                  int *period,
                  char *placeholder);

/**
 * Функція запису у файл
 * 
 * Опис роботи: 
 *  - По символьно вписати графік функції до файлу
 * @param f об'єкт файлу
 * @param data графік функції
 */
void writeToFile(FILE *f, 
                 char **data,
                 unsigned int height,
                 unsigned int length);

/**
 * Функція малювання графіку функції
 * 
 * Опис роботи: 
 *  - Спочатку заповнити матрицю пробілами
 *  - Потім у циклі завдяки математичним розрахункам малювати посимвольно функцію
 * @param amplitude амплітуда функції
 * @param period період функції
 * @param placeholder символ заповнювач
 * @param data матриця функції
 */
void drawData(int amplitude, 
              int period,
              char placeholder,
              char **data,
              unsigned int height,
              unsigned int length);

/**
 * Функція виводу до консолі
 * 
 * Опис роботи: 
 *  - Виводить зміст файлу, в який було записано результат
 */
void printData();

#endif
