/**
 * @file main.c
 * @brief Файл з демонстрацією виконаноії роботи
 *
 * @author Sobolenko S.
 * @version 0.0.1
 * @date 06-jul-2022
 */

#include "lib.h"

/**
 * Основна функція
 * 
 * Опис роботи: 
 * - Зберігаємо шляхи вхідного/вихідного файлів
 * - Зчитуємо дані з файлу
 * - Записуємо дані до файлу
 * - Виводимо дані у консоль
 * - Знаходимо пошкоджені лампочки
 * - Сортуємо дані
 * @param argv шлях вхідного та вихідного файлі
 * @return успішний код повернення з програми (0)
 */
int main(int argc, char **argv)
{
	(void)argc;

	char *inputPath = *(argv + 1);
	char *outputPath = *(argv + 2);

	struct Lamp *lamps = (struct Lamp *)malloc(LAMP_NUMBER * sizeof(struct Lamp));

	readFromFile(inputPath, lamps);

	writeToFile(outputPath, lamps);

	printStructure(lamps);

	struct Lamp *brokenLamps = (struct Lamp *)malloc(LAMP_NUMBER * sizeof(struct Lamp));
	getBrokenLamps(lamps, brokenLamps);

	sortByField(lamps);

	free(lamps);
	free(brokenLamps);
	lamps = brokenLamps = NULL;

	return 0;
}