/**
 * @file lib.c
 * Implementation of functions for lab09.
 * @author sergey_sobolenko
 * @version 0.0.1
 * @date 15.02.2022
 */
 #include "lib.h"
 
int get_words_count(char string[], int string_len){
    
    /* Задаю початкове значення кількості знайдених слів */
    int words_count = 0;
    
    /* Якщо перший сивол тексту не є пробілом, то хоча б одне слово знайдено */ 
    if(string[0] != ' '){
        words_count = 1;
    }
    
    /* Проходжусь по кожному символу у тексті, починаючи з другого, та визначаю кількість слів */
    for(int i = 1; i < string_len; i++){
        
        /* Шаблон виявлення слова: якщо даний символ не є пробілом, а попередній є, то маємо нове слово */
        if(string[i] != ' ' && string[i-1] == ' '){
            words_count++;
        }
    }
    
    return words_count;
}


bool is_number_great(int number){
    
    /* Змінна для суми усіх дільників числа */
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
        return true;
    }
    
    return false;
}
