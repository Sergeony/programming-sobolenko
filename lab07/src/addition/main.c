/*
 * author: Sergey Sobolenko
 * date: 22-dec-2021
 */
#include <stdio.h>
#include <string.h>

int get_pairs_count(int consequence[], int consequence_length);

/*
 * # 1. Загальне завдання
 * Розробка програм з функціями
 * # 2. Індивідуальне завдання
 * Номер завдання з лабораторної роботи - додаткове завдання 
 * Реалізувати функцію, що визначає, скільки серед заданої послідовності чисел таких пар, у
котрих перше число більш наступного.
 * # 3. Хід виконання програми
 * Проходжусь циклом по всім елементам послідовності, та якщо поточний елемент більше попереднього, то збільшую кількість знайдених пар чисел.
 */
int main() {

    /* Задаю довжину послідовністі */
    #define NUMBERS_COUNT 5
    /* Задаю послідовність чисел */
    int numbers [NUMBERS_COUNT] = {3, 2, 4, 3, 1};
    /* Результуюча кількість пар у яких перше число більше другого */
    int result = get_pairs_count(numbers, NUMBERS_COUNT);

    return 0;
}

int get_pairs_count(int consequence[], int consequence_length) {

    /* Задаю лічильник кількості знайдених пар */
    int pairs_count = 0;

    /* Проходжусь по всім числам послідовності починаючи з другого для визначення кількості пар */
    for(int i = 1; i < consequence_length; i++) {
    	
    	/* Якщо i-те число менше ніж (i-1)-ше число, то збільшуємо кількість пар */
        if(consequence[i] < consequence[i-1]) {
            pairs_count++;
        }
    }
    
    return pairs_count;
}

