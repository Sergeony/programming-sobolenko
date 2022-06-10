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
 * - Створюємо строку
 * - Зчитуємо у строку значення з консолі
 * - Конвертуємо значення у число
 * - Виводимо значення до консолі
 * @return успішний код повернення з програми (0)
 */
int main(void)
{
	char *string = (char *)malloc(BUFFER_SIZE * sizeof(char));
	double result;

	printf("Enter the number please: ");
	fgets(string, BUFFER_SIZE, stdin);

	result = convertToNumber(string);

	printf("Result as number: %lf\n", result);

	free(string);
	string = NULL;

	return 0;
}
