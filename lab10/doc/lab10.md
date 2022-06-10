# Лабораторна робота №10. Вступ до показчиків

## 1 Вимоги

### 1.1 Розробник

* Соболенко Cергій Сергійович;
* студент групи КН-921б;
* 30-may-2021.

### 1.3 Індивідуальне завдання

14.(**) Дано масив масивів з N*N цілих чисел. Елементи головної діагоналі записати водновимірний масив, отриманий масив упорядкувати за зростанням.

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для збереження елементів с головної діагоналі до масиву та відсортування їх
за зростанням.

### 2.2 Опис логічної структури

#### Функція заповнення діагоналі

```c
		fillDiagonal(int **matrix, int *diagonal);
```

*Призначення*: Заповнення необхідними елементами результуючий масив.

*Опис роботи*:
    - Заповнює масив елементами в яких рядок дорівнює стовбцю.

#### Функція сортування

```c
		bubbleSort(int *diagonal);
```

*Призначення*: Сортування елементів у вихідному масиві діагоналі.

*Опис роботи*: 
    - Сортує звичайним бульбашковим алгоритмом за зростанням.

#### Основна функція

```c
		int main(void)
```

*Призначення*: демонстрація виконаної роботи.

*Опис роботи*: 

    - Створюємо двовимірний масив matrix.
    - Заповнюємо його випадковими значеннями.
    - Створюємо вихідний масив diagonal.
    - Заповнюємо його елементами на головній діагоналі.
    - Сортуємо за зростанням.
    - Звільняємо пам'ять.

#### Структура проекту

```
        lab10
        ├── doc
        │   ├── assets
        │   └── lab10.md
        ├── Doxyfile
        ├── Makefile
        ├── README.md
        ├── src
        │   ├── lib.c
        │   ├── lib.h
        │   └── main.c
        └── test
            └── test.c

```

### 2.3 Важливі фрагменти програми

#### Початкові дані

```c
        /**
         * Розмір квадратної вхідної матриці
         */
        #define COLS_AND_ROWS 3
```

#### Заповнення масиву діагональних елементів

```c
        void fillDiagonal(int **matrix, int *diagonal)
        {
            for (int i = 0; i < COLS_AND_ROWS; i++) {
                *(diagonal + i) = *(*(matrix + i) + i);
            }
        }
```

#### Сортування масиву

```c
        void bubbleSort(int *diagonal)
        {
            for (int i = 0; i < COLS_AND_ROWS; i++) {
                for (int j = 0; j < COLS_AND_ROWS - i - 1; j++) {

                    if (*(diagonal + j) > *(diagonal + (j + 1))) {

                        int temp = *(diagonal + j);
                        *(diagonal + j) = *(diagonal + (j + 1));
                        *(diagonal + (j + 1)) = temp;
                    }
                }
            }
        }
```

## Варіанти використання

**Варіант використання 1**: послідовність дій для запуску програми у режимі відлагодження:

- запустити програму у відлагоднику lldb;
- поставити точку зупинки на функції main (строка 40);
- запустити програму;
- подивитись результати виконання програми, оглядаючи значення змінної diagonal

```
        Process 293954 stopped
        * thread #1, name = 'main.bin', stop reason = breakpoint 2.1
            frame #0: 0x0000000000401360 main.bin`main at main.c:40:17
            37  	
            38  	    /* Fill diagonal and sort it. */
            39  	    fill_diagonal(matrix, diagonal);
         -> 40  	    bubble_sort(diagonal);
            41  	
            42  	    /* Free memory */
            43  		for (int i = 0; i < COLS_AND_ROWS; i++) {
        (lldb) fr v diagonal Z3
        (int *) diagonal = 0x0000000000405320
        error: no variable named 'Z3' found in this frame
        (lldb) fr v diagonal -Z3
        (int *) diagonal = 0x0000000000405320 {
            (int) [0] = 0
            (int) [1] = 9
            (int) [2] = 6
        }
```
**Варіант використання 2**: запустити тести с з покриттям
```
        Filename                                                         Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover
        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        /home/sergey/Documents/programming-sobolenko/lab10/src/lib.c          16                 0   100.00%           2                 0   100.00%          18                 0   100.00%
        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        TOTAL                                                                 16                 0   100.00%           2                 0   100.00%          18                 0   100.00%
        llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html

```

**Витоків пам'яті немає**
```
        ==297216== Memcheck, a memory error detector
        ==297216== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
        ==297216== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
        ==297216== Command: dist/main.bin
        ==297216== 
        ==297216== 
        ==297216== HEAP SUMMARY:
        ==297216==     in use at exit: 0 bytes in 0 blocks
        ==297216==   total heap usage: 5 allocs, 5 frees, 72 bytes allocated
        ==297216== 
        ==297216== All heap blocks were freed -- no leaks are possible
        ==297216== 
        ==297216== For lists of detected and suppressed errors, rerun with: -s
        ==297216== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи з динамічними
струкутрами, а також відстеження витоків памʼяті.