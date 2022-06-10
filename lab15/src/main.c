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

	int lamps_number = 3;

	struct LampContainer *container = malloc(sizeof(struct LampContainer));
	container->lamps = malloc((unsigned)lamps_number * sizeof(struct Lamp));
	container->size = lamps_number;

	readFromFile(inputPath, container);

	printf("\nArray before appending a new item and deleting 0 item:\n");
	printStructure(container);

	struct Lamp new_lamp;
	new_lamp.isBroken = 1;
	new_lamp.isTurnedOn = 1;
	strcpy(new_lamp.manufacturer, "Meizu");
	new_lamp.leftStarts = 20;
	new_lamp.wattPerHour = 20;
	new_lamp.colourTemperature = 2000;
	new_lamp.shape = 2;
	new_lamp.plinthType = 2;
	
	append(container, &new_lamp);

	del_item(container, 0);

	printf("\nResult array:\n");
	printStructure(container);

	struct LampContainer *brokenLamps =  malloc(sizeof(struct LampContainer));
	brokenLamps->size = 0;

	getBrokenLamps(container, brokenLamps);

	sortByField(container);

	writeToFile(outputPath, container);

	free(container->lamps);
	free(container);
	free(brokenLamps->lamps);
	free(brokenLamps);
	container = brokenLamps = NULL;

	return 0;
}