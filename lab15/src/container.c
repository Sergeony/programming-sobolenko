#include "lib.h"

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
