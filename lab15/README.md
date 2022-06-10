# Лабораторна робота No15. Динамічні масиви

## 1 Вимоги

### 1.1 Розробник

* Соболенко Cергій Сергійович;
* студент групи КН-921б;
* 06-jul-2021.

### 1.3 Індивідуальне завдання

На базі попередньо розробленого функціоналу по роботі з прикладною областю сформуватидинамічний масивелементів розробленої структури. Реалізувати наступні функції роботи зісписком:
- вивід вмісту списку на екран;
- реалізувати функцію No1 з категорії “Методи для роботи з колекцією” (див. завдання з РЗ);
- додавання об’єкта у кінець списку;
- видалення об’єкта зі списку за індексом.
- сортування вмісту списку за одним з критеріїв

## 2 Опис програми

### 2.1 Функціональне призначення

Імлементувати динамічний масив для роботи зі структурами, що були створені у минулій лабораторній роботі

### 2.2 Важливі фрагменти програми

#### Структура контейнеру

```c
        struct LampContainer {
            struct Lamp *lamps;
            int size;
        };
```

### Функція додання елементу в кінець масиву

```c
        void append(struct LampContainer *container,
                struct Lamp *new_item)
        {
            struct Lamp *new_lamps = malloc((unsigned)(container->size + 1) * sizeof(struct Lamp));

            memcpy(new_lamps, 
                container->lamps,
                (unsigned)(container->size) * sizeof(struct Lamp));
            
            memcpy(new_lamps + container->size,
                new_item,
                sizeof(struct Lamp));

            free(container->lamps);
            container->lamps = new_lamps;
            container->size++;
        }
```
### Функція видалення елементу за індексом

```c
        void del_item(struct LampContainer *container,
                    int pos)
        {
            struct Lamp *new_lamps = malloc((unsigned)(container->size - 1) * sizeof(struct Lamp));

            memcpy(new_lamps, 
                container->lamps,
                (unsigned)pos * sizeof(struct Lamp));

            memcpy(new_lamps + pos,
                (container->lamps + pos + 1),
                (unsigned)(container->size - pos - 1) * sizeof(struct Lamp));

            free(container->lamps);
            container->lamps = new_lamps;
            container->size--;
        }
```

## Варіанти використання

**Варіант використання 1**: послідовність дій для запуску програми у консолі:

- запустити програму;
- подивитись результати виконання програми;

```
        Array before appending a new item and deleting 0 item:
        {0 1 Nokia 15 10 6600 1 1}
        {0 1 Apple 0 15 1800 1 1}
        {1 0 Xiaomi 10 5 1600 0 0}

        Result array:
        {0 1 Apple 0 15 1800 1 1}
        {1 0 Xiaomi 10 5 1600 0 0}
        {1 1 Meizu 20 20 2000 2 2}
```

**Витоків пам'яті немає**
```
        ==103451== HEAP SUMMARY:
        ==103451==     in use at exit: 0 bytes in 0 blocks
        ==103451==   total heap usage: 12 allocs, 12 frees, 11,804 bytes allocated
        ==103451== 
        ==103451== All heap blocks were freed -- no leaks are possible
```

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи з динамічними масивами та операціями над нами.