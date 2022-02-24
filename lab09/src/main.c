/**
 * @file main.c
 * Entry point.
 * @author sergey_sobolenko
 * @version 0.0.1
 * @date 15.02.2022
 */
#include "lib.h"

/**
 * Entry point.
 * @return exit code
 */
int main() {
    
    srand(time(NULL));

    /* Задаю значения даного числа */
    int number = rand() % 10;
    /* Оголошую змінну, що буду означати результат*/
    bool result_1 = is_number_great(number);
    


    /* Задаю довжину тексту*/
    #define TEXT_LEN 7
    /* Задаю даний текст */
    char text[TEXT_LEN];
    
    /* Випадково заповнюю даний текст */
    for(int i = 0; i < TEXT_LEN; i++){
        
        /* Якщо число = 1, то присвоюється випадкова літера, а якщо число = 0, то пробіл */
        text[i] = rand() % 2 ? rand() % 26 +'A' : ' ';
    }
    
    /* Результуюча кількість слів */
    int result_2 = get_words_count(text, TEXT_LEN);
    
    return 0;
}
