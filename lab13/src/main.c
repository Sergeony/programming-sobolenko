/**
 * @file main.c
 * @brief Файл з демонстрацією виконаноії роботи
 *
 * @author Sobolenko S.
 * @version 0.0.1
 * @date 05-jul-2022
 */

#include "lib.h"

/**
 * Основна функція
 * 
 * Опис роботи: 
 * - Сторюємо змінні з путями до файлів вводу/виводу
 * - Ініціюємо змінні для шуканою функції
 * - Зчитуємо значення з файлу
 * - Створюємо матрицю вказаного розміру
 * - Малюємо графік
 * - Записуємо результат до файлу
 * - Виводимо результат до консолі
 * @return успішний код повернення з програми (0)
 */
int main(int argc, char **argv)
{
	(void)argc;

	char *inputPath = *(argv + 1);
	char *outputPath = *(argv + 2);

	int amplitude = 0, period = 0;
	char placeholder = ' ';

	FILE *inputFile = fopen(inputPath, "r");
	readFromFile(inputFile, &amplitude, &period, &placeholder);
	fclose(inputFile);

	unsigned int BUFFER_LENGTH = (unsigned)period;
	unsigned int BUFFER_HEIGHT = (unsigned)amplitude * 2 + 1;

	char **data = (char **)malloc(BUFFER_HEIGHT * sizeof(char *));
	for (unsigned int i = 0; i < BUFFER_HEIGHT; i++) {
		*(data + i) = (char *)malloc(BUFFER_LENGTH * sizeof(char));
	}

	drawData(amplitude, period, placeholder, data, BUFFER_HEIGHT, BUFFER_LENGTH);

	FILE *outputFile = fopen(outputPath, "w");
	writeToFile(outputFile, data, BUFFER_HEIGHT, BUFFER_LENGTH);
	fclose(outputFile);

	printData(data);

	for (unsigned int i = 0; i < BUFFER_HEIGHT; i++) {
		free(*(data + i));
	}
	free(data);
	data = NULL;

	return 0;
}