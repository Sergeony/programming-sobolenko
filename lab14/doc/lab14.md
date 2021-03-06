# Лабораторна робота No14. Структуровані типи даних

## 1 Вимоги

### 1.1 Розробник

* Соболенко Cергій Сергійович;
* студент групи КН-921б;
* 06-jul-2021.

### 1.3 Індивідуальне завдання

• розробити функцію, яка читає дані (масив елементів) з файлу;
• розробити функцію, яка записує дані (масив елементів) у файл;
• розробити функцію, яка виводить масив елементів на екран;
• реалізувати функцію No1 з категорії “Методи для роботи з колекцією”;
• розробити функцію, яка буде сортувати масив елементів за заданим критерієм (полем);

*Поля базового класу:*
- Чи ввімкнена лампочка (наприклад: так, ні)
- Чи перегоріла лампочка (наприклад: так, ні)
- Виробник лампочки (наприклад: ТОВ Рога та Копита)
- Кількість вмикань лампочки до перегоряння, зворотній лічильник (наприклад: 20,250)
- Кількість ватт, які лампочка споживає кожну годину (наприклад: 5, 10, 15)
- Температура кольору світіння лампочки (наприклад: 1800, 6600)
- Форма (один з переліку: Candle, Tubular, Globe, Pear, Ogive)
- Тип цоколю (один з переліку: E14, E27, E40)

*Методи для роботи з колекцією:*
    1. Знайти перегорілі лампочки

## 2 Опис програми

### 2.1 Функціональне призначення

Зчитати початкові дані з файлу, записати дані до файлу,
вивести дані до консолі, знайти пошкоджені лампочки
та відсортувати лампочки за кількістю включень до поломки.

### 2.2 Опис логічної структури

#### Функція зчитування даних з файлу

```c
    void readFromFile(char *fileName,
                      struct Lamp *lamps);
```

*Призначення*: Зчитати масив лампочок з файлу

 *Опис роботи:* 
  - По рядкам зчитувати дані та форматованим рядком записувати до полів структури

#### Функція запису у файл

```c
    void writeToFile(char *fileName,
                    struct Lamp *lamps);
```

*Призначення*: Записати у файл масив лампочок

 *Опис роботи:* 
 - У циклі пройтись по всьому масиву та записати усі поля до файлу

#### Функція виводу масиву елементів на екран

```c
    void printStructure(struct Lamp *lamps);
```

*Призначення*: вивести масив до консолі

*Опис роботи:* 
 - Пройтись у циклі по всьому масиві та вивести елементи до консолі

#### Функція знаходження пошкоджених лампочок

```c
		void getBrokenLamps(struct Lamp *lamps,
                    struct Lamp *brokenLamps);
```

*Призначення*: Виявити пошкоджені лампочки

 *Опис роботи:*
  - У циклі, перевіряючи значення відповідного поля, записує пошкоджені лампочки до результуючого масиву

### Функція сортування елементів за заданими полем

*Призначення:* Відсортувати за кількістю включень до поломки

 *Опис роботи:*
  - Методом звичайного бульбашкового сортування
  сорутє за зростанням значення кількості включень до поломки

```c
		void sortByField(struct Lamp *lamps);
```
#### Основна функція

```c
		int main(argc, **argv);
```

*Призначення*: демонстрація виконаної роботи.

 *Опис роботи: *
  - Зберігаємо шляхи вхідного/вихідного файлів
  - Зчитуємо дані з файлу
  - Записуємо дані до файлу
  - Виводимо дані у консоль
  - Знаходимо пошкоджені лампочки
  - Сортуємо дані

#### Структура проекту

```
    lab14
    ├── assets
    │   └── input.txt
    ├── doc
    │   └── lab14.md
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

#### Структура та перерахування

```c
    /**
     * Поле форм цоколів
     */
    enum Shape {Candle, Tubular, Globe, Pear, Ogive};

    /**
     * Поле типів цоколів
     */
    enum PlinthType {E14, E27, E40};

    /**
     * Структура - лампочка
     */
    struct Lamp {
        bool isTurnedOn;
        bool isBroken;
        char manufacturer[MAX_STRING_LENGTH];
        int leftStarts;
        int wattPerHour;
        int colourTemperature;
        enum Shape shape;
        enum PlinthType plinthType;
    };
```

## Варіанти використання

**Варіант використання 1**: послідовність дій для запуску програми у консолі:

- запустити програму;
- подивитись результати виконання програми;

```
    {0 1 Nokia 15 10 6600 1 1}
    {0 1 Apple 0 15 1800 1 1}
    {1 0 Xiaomi 10 5 1600 0 0}
```

**Витоків пам'яті немає**
```
    ==78505== Memcheck, a memory error detector
    ==78505== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==78505== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
    ==78505== Command: ./dist/main.bin ./assets/input.txt ./dist/output.txt
    ==78505== 
    {0 1 Nokia 15 10 6600 1 1}
    {0 1 Apple 0 15 1800 1 1}
    {1 0 Xiaomi 10 5 1600 0 0}
    ==78505== 
    ==78505== HEAP SUMMARY:
    ==78505==     in use at exit: 0 bytes in 0 blocks
    ==78505==   total heap usage: 7 allocs, 7 frees, 10,904 bytes allocated
    ==78505== 
    ==78505== All heap blocks were freed -- no leaks are possible
    ==78505== 
    ==78505== For lists of detected and suppressed errors, rerun with: -s
    ==78505== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи зі структуровими типами даних, таких як структура а також перерахування.