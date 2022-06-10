# Лабораторна робота No12. Строки (Null-terminated C Strings)

## 1 Вимоги

### 1.1 Розробник

* Соболенко Cергій Сергійович;
* студент групи КН-921б;
* 05-jul-2021.

### 1.3 Індивідуальне завдання

22.(**) ББез використання зовнішніх функцій необхідно реалізувати функції перетвореннястроки, що представляє собою число до фактичного числа (supported types: int, float). Урамках завдання можемо вважати, що строка не має помилок та має лише число

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для конвертування дійсного числа у текстовому форматі до числового.

### 2.2 Опис логічної структури

#### Функція конвертації у число

```c
		convertToNumber(const char *string);
```

*Призначення*: Перевести число зі строкового типу до числового.

 *Опис роботи*: 
   - Доки не зустріниться точка, помножати результат на 10 та додавати нову цифру
   - Після того як зустрілась точка, кожну цифру ділити на 10 у ступені порядка цифри після точки
   та додавати до результату

#### Основна функція

```c
		int main(void)
```

*Призначення*: демонстрація виконаної роботи.

 *Опис роботи*: 
  - Створюємо строку
  - Зчитуємо у строку значення з консолі
  - Конвертуємо значення у число
  - Виводимо значення до консолі

#### Структура проекту

```
        lab12
        ├── assets
        │   └── input.txt
        ├── doc
        │   └── lab12.md
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
         * Кількість символів
         */
        #define BUFFER_SIZE 1000
```

#### Функція конвертації у число

```c
        double convertToNumber(const char *string) {
            char terminatedChar = '\0';
            double number = 0;
            bool afterPoint = false;
            double place = 1;

            for (int i = 0; *(string + i) != '\n' && *(string + i) != '\0'; i++) {
                if (*(string + i) == '.') {
                    afterPoint = true;
                    continue;
                }

                int digit = *(string + i) - '0';

                if (afterPoint) {
                    place /= 10;
                    number += digit * place;
                } else {
                    number *= 10;
                    number += digit;
                }
            }

            return number;
        }
```

## Варіанти використання

**Варіант використання 1**: послідовність дій для запуску програми у консолі:

- запустити програму;
- ввести число;
- подивитись результати виконання програми;

```
        Enter the number please: 1234.432
        Result as number: 1234.432000
```

**Варіант використання 2**: запустити тести с з покриттям

```
        Filename                                                         Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover
        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        /home/sergey/Documents/programming-sobolenko/lab12/src/lib.c          12                 0   100.00%           1                 0   100.00%          25                 0   100.00%
        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        TOTAL                                                                 12                 0   100.00%           1                 0   100.00%          25                 0   100.00%
        cd dist/ && llvm-cov show test.bin -instr-profile=default.profdata ../src/*.c --format html > coverage.html

```

**Витоків пам'яті немає**
```
        ==23460== Memcheck, a memory error detector
        ==23460== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
        ==23460== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
        ==23460== Command: ./dist/main.bin
        ==23460== 
        Enter the number please: 123.12
        Result as number: 123.120000
        ==23460== 
        ==23460== HEAP SUMMARY:
        ==23460==     in use at exit: 0 bytes in 0 blocks
        ==23460==   total heap usage: 3 allocs, 3 frees, 3,048 bytes allocated
        ==23460== 
        ==23460== All heap blocks were freed -- no leaks are possible
        ==23460== 
        ==23460== For lists of detected and suppressed errors, rerun with: -s
        ==23460== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи з термінованими строками та перенаправленням потоків.