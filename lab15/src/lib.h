#ifndef __LIB_H__
#define __LIB_H__

/**
 * @file lib.h
 * @brief Файл з вхідними даними та перерахуванням функцій
 *
 * @author Sobolenko S.
 * @date 06-jul-2022
 * @version 0.0.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "container.h"

/**
 * Максимальна довжина рядку
 */
#define MAX_STRING_LENGTH 100

/**
 * Поле форм цоколів
 */
enum Shape {Candle, Tubular, Globe, Pear, Ogive};

/**
 * Поле типів цоколів
 */
enum PlinthType {E14, E27, E40};

/**
 * Структура - лампочка
 */
struct Lamp {
    bool isTurnedOn;
    bool isBroken;
    char manufacturer[MAX_STRING_LENGTH];
    int leftStarts;
    int wattPerHour;
    int colourTemperature;
    enum Shape shape;
    enum PlinthType plinthType;
};

/**
 * Функція зчитування даних з файлу
 * 
 * Опис роботи: 
 *  - По рядкам зчитувати дані та форматованим рядком записувати до полів структури
 * @param fileName назва файлу
 * @param lamps вхідний масив
 */
void readFromFile(char *fileName,
                  struct LampContainer *container);

/**
 * Функція запису у файл
 * 
 * Опис роботи: 
 *  - У циклі пройтись по всьому масиву та записати усі поля до файлу
 * @param fileName назва файлу
 * @param lamps вхідний масив
 */
void writeToFile(char *fileName,
                 struct LampContainer *container);

/**
 *  Функція виводу масиву елементів на екран
 * 
 * Опис роботи: 
 *  - Пройтись у циклі по всьому масиві та вивести елементи до консолі
 * @param lamps вхідний масив
 */
void printStructure(struct LampContainer *container);

/**
 *  Функція знаходження пошкоджених лампочок
 * 
 * Опис роботи: 
 *  - У циклі, перевіряючи значення відповідного поля, записує пошкоджені лампочки
 *  до результуючого масиву
 * @param lamps вхідний масив
 * @param brokenLamps вихідний масив
 */
void getBrokenLamps(struct LampContainer *container,
                    struct LampContainer *brokenContainer);

/**
 *  Функція сортування елементів за заданими полем
 * 
 * Опис роботи: 
 *  - Методом звичайного бульбашкового сортування
 *  сорутє за зростанням значення кількості включень до поломки
 * @param lamps вхідний масив
 */
void sortByField(struct LampContainer *container);

#endif
