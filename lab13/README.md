# Лабораторна робота No13. Взаємодія з файлами

## 1 Вимоги

### 1.1 Розробник

* Соболенко Cергій Сергійович;
* студент групи КН-921б;
* 05-jul-2021.

### 1.3 Індивідуальне завдання

3.(**) Розробити програму, що в заданому файлі створює горизонтальну синусоїду із заданихсимволів (наприклад, зірочок). Амплітуда синусоїди, символ заповнювача та періодзадається у вхідному файлу.

## 2 Опис програми

### 2.1 Функціональне призначення

Зчитати початкові дані з файлу, побудувати на їх основі графік функції та записати його до файлу

### 2.2 Опис логічної структури

#### Функція зчитування початкових даних з файлу

```c
        void readFromFile(FILE *f, 
                          int *amplitude, 
                          int *period,
                          char *placeholder);
```

*Призначення*: Зчитати початкові дані з файлу

 *Опис роботи*: 
  - Перевірити файл на вмістимість
  - Зчитати три змінних
  - Закрити файл

#### Функція запису у файл

```c
        void writeToFile(FILE *f, 
                         char **data,
                         unsigned int height,
                         unsigned int length);
```

*Призначення*: Записати у файл графік функції

 *Опис роботи*: 
  - По символьно вписати графік функції до файлу

#### Функція малювання графіку функції

```c
		void drawData(int amplitude, 
                      int period,
                      char placeholder,
                      char **data,
                      unsigned int height,
                      unsigned int length);
```

*Призначення*: Побудувати графік функції

 *Опис роботи*: 
  - Спочатку заповнити матрицю пробілами
  - Потім у циклі завдяки математичним розрахункам малювати посимвольно функцію

#### Функція виводу до консолі

```c
		void printData();
```

*Призначення*: Вивести результат до консолі

 *Опис роботи*: 
   - Системною командою виводить зміст файлу

#### Основна функція

```c
		int main(void);
```

*Призначення*: демонстрація виконаної роботи.

 *Опис роботи*: 
  - Сторюємо змінні з путями до файлів вводу/виводу
  - Ініціюємо змінні для шуканою функції
  - Зчитуємо значення з файлу
  - Створюємо матрицю вказаного розміру
  - Малюємо графік
  - Записуємо результат до файлу
  - Виводимо результат до консолі

#### Структура проекту

```
        lab13
        ├── assets
        │   └── input.txt
        ├── dist
        │   ├── main.bin
        │   └── output.txt
        ├── doc
        │   └── lab13.md
        ├── Doxyfile
        ├── Makefile
        ├── README.md
        ├── src
        │   ├── lib.c
        │   ├── lib.h
        │   └── main.c
        └── test
```

### 2.3 Важливі фрагменти програми

#### Константи

```c
        /**
         * Математична константа пі
         */
        #define PI 3.14159
```

#### Функція зчитування початкових даних з файлу

```c
        void readFromFile(FILE *f, 
                            int *amplitude, 
                            int *period,
                            char *placeholder)
        {
            if (f != NULL) {
                fscanf(f, "%d %d %c", amplitude, period, placeholder);
            } else {
                exit(1);
            }
        }
```

#### Функція запису у файл

```c
        void writeToFile(FILE *f, 
                        char **data,
                        unsigned int height,
                        unsigned int length)
        {
            for (unsigned int i = 0; i < height; i++) {
                for (unsigned int j = 0; j < length; j++) {
                    fprintf(f, "%c", *(*(data + i) + j));
                }
                fprintf(f, "%c", '\n');
            }
        }
```

#### Алгоритм побудови графіку функції

```c
    for (int x = 0, y; x < period; x++) {
        y = -(int)round((amplitude * sin(x * PI / (period / 2)))) + amplitude;

        *(*(data + y) + x) = placeholder;
    }
```

## Варіанти використання

**Варіант використання 1**: послідовність дій для запуску програми у консолі:

- запустити програму;
- подивитись результати виконання програми;

```
                *****                           
             ***     ***                        
            *           *                       
          **             **                     
         *                 *                    
        *                   *                   
                             *                 *
                              **             ** 
                                *           *   
                                 ***     ***    
                                    *****       

```


**Витоків пам'яті немає**
```
        ==42847== Memcheck, a memory error detector
        ==42847== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
        ==42847== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
        ==42847== Command: ./dist/main.bin ./assets/input.txt ./dist/output.txt
        ==42847== 
                *****                           
             ***     ***                        
            *           *                       
          **             **                     
         *                 *                    
        *                   *                   
                             *                 *
                              **             ** 
                                *           *   
                                 ***     ***    
                                    *****       

        ==42847== 
        ==42847== HEAP SUMMARY:
        ==42847==     in use at exit: 0 bytes in 0 blocks
        ==42847==   total heap usage: 16 allocs, 16 frees, 9,664 bytes allocated
        ==42847== 
        ==42847== All heap blocks were freed -- no leaks are possible
        ==42847== 
        ==42847== For lists of detected and suppressed errors, rerun with: -s
        ==42847== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи з файлами.