#ifndef __CONTAINER_H__
#define __CONTAINER_H__

/**
 * @brief Контейнер динамічного масиву лампочок
 */
struct LampContainer {
    struct Lamp *lamps;
    int size;
};

/**
 * @brief Функція додавання елементу у кінець масиву
 * 
 * @param container контейнер масиву
 * @param new_item новий елемент
 */
void append(struct LampContainer *container,
            struct Lamp *new_item);

/**
 * @brief Функція видалення за індексом
 * 
 * @param container контейнер масиву
 * @param pos індекс видаляємого елементу
 */
void del_item(struct LampContainer *container,
              int pos);


#endif
