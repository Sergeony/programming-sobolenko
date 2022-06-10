/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Sobolenko S.
 * @date 05-jul-2022
 * @version 0.0.1
 */

#include "lib.h"

void fillMatrix(double **matrix) {
    printf("\nFill the matrix with values between [-1000.0, +1000.0]: \n\n");

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            double element = 1001; // if user will skip, accidentally

            label:
                printf("Enter element on row %d  and col %d: ", i, j);
                                
                scanf("%lf", &element);

                if (element < -1000.0 || element > 1000.0) {
                    printf("Element out of range, reenter please!\n");
                    goto label;
                }
                *(*(matrix + i) + j) = element;
        }
    }
}

void sumMatrices(double **matrix1,
                 double **matrix2, 
                 double **resultMatrix)
{
    for(int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(*(resultMatrix + i) + j) = *(*(matrix1 + i) + j) + *(*(matrix2 + i) + j);
        }
    }
}

void printMatrix(double **matrix) {
    printf("\n"); 
    for (int i = 0; i < ROWS; i++) {
        printf("[");
        
        for (int j = 0; j < COLS; j++) {
            printf("%.2f\t", *(*(matrix + i) + j));
        }

        printf("]\n");
    }
}