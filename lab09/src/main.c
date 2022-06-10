/**
 * @file main.c
 * @brief Файл з демонстрацією виконаноії роботи
 * 
 * @author Sobolenko S.
 * @version 0.0.1
 * @date 15-feb-2022
 */

#include "lib.h"

/**
 * Основна функція
 * 
 * Опис роботи: 
 * - Створюємо випадкове число
 * - Перевіряємо чи є воно досконалим
 * 
 * - Створюємо текст с випадковими(неіснуючими) словами
 * - Знаходимо кількість слів у тексті
 * 
 * @return успішний код повернення з програми (0)
 */
int main() {

	time_t t;
	srand((unsigned) time(&t));

    int number = rand() % 10;

    bool result1 = isNumberGreat(number);
    
    char text[TEXT_LEN];
    for(int i = 0; i < TEXT_LEN; i++) {    
        /* Якщо число = 1, то присвоюється випадкова літера, інакше пробіл */
        text[i] = rand() % 2 ? rand() % 26 +'A' : ' ';
    }
    
    int result_2 = getWordsCount(text, TEXT_LEN);
    
    return 0;
}
