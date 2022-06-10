/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 * 
 * @author Sobolenko S.
 * @version 0.0.1
 * @date 15-feb-2022
 */

 #include "lib.h"
 
int getWordsCount(char string[], int stringLen) {
    
    int wordsCount = 0;
    
    if(string[0] != ' ') {
        wordsCount = 1;
    }
    
    for(int i = 1; i < stringLen; i++) {
        if(string[i] != ' ' && string[i-1] == ' ') {
            wordsCount++;
        }
    }
    
    return wordsCount;
}


bool isNumberGreat(int number) {
    
    int sum = 1;
        
    for(int i = 2; i < number; i++) {
        if(number % i == 0){
            sum += i;
        }
    }
    
    if(sum == number) {
        return true;
    }
    
    return false;
}
