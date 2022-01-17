/*
 * author: Sergey Sobolenko
 * date: 22-nov-2021
 */
#include <stdio.h>
#include <stdbool.h>

/*
 * # 1. Загальне завдання
 * Розробка програм c циклічними конструкціями
 * # 2. Індивідуальне завдання
 * Номер завдання з лабораторної роботи - 24  
 * Визначити, чи є задане число досконалим (якщо воно дорівнює сумі своїх дільників).
 * # 3. Хід виконання програми
 * У циклі знаходжу усі дільники числа та сумую їх, після чого порівнюю с даним числом
 */
int main() {

    /* Задаю значения даного числа */
    int number = 6;
    /* Оголошую змінну, що буду означати результат*/
    bool result;
    /* Змінна для суми усіх дільників числа*/
    int sum = 0;

    /* Проходжу циклом по всім числам від 1 до даного та визначаю його дільники */    
    for(int i = 1; i < number; i++){
        
        /* Умова, що визначає чи є число дільником */
        if(number % i == 0){
            sum += i;
        }
    }
    
    /* В залежності від отриманої суми визначаю результат */
    if(sum == number){
        result = true;
    }
    else{
        result = false;
    }
    
    return 0;
}
