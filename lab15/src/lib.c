/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Sobolenko S.
 * @date 06-jul-2022
 * @version 0.0.1
 */

#include "lib.h"

void readFromFile(char *fileName,
                  struct LampContainer *container)
{
    FILE *file = fopen(fileName, "r");
    char line[MAX_STRING_LENGTH];

    for (int i = container->size - 1; fscanf(file, "%[^\n]", line) != EOF; i--) {
        fgetc(file);
        int tempIsTurnedOn = 1, tempIsBroken = 1;

        sscanf(line, 
               "%d %d %s %d %d %d %u %u",
               &tempIsTurnedOn,
               &tempIsBroken,
               (container->lamps + i)->manufacturer,
               &(container->lamps + i)->leftStarts,
               &(container->lamps + i)->wattPerHour,
               &(container->lamps + i)->colourTemperature,
               &(container->lamps + i)->shape,
               &(container->lamps + i)->plinthType);

        (container->lamps + i)->isTurnedOn = tempIsTurnedOn;
        (container->lamps + i)->isBroken = tempIsBroken;
    }
    
    fclose(file);
}

void writeToFile(char *fileName,
                 struct LampContainer *container)
{
    FILE *file = fopen(fileName, "w");

    for (int i = 0; i < container->size; i++) {
        fprintf(file, 
                "%d %d %s %d %d %d %d %d\n",
                (container->lamps + i)->isTurnedOn,
                (container->lamps + i)->isBroken,
                (container->lamps + i)->manufacturer,
                (container->lamps + i)->leftStarts,
                (container->lamps + i)->wattPerHour,
                (container->lamps + i)->colourTemperature,
                (container->lamps + i)->shape,
                (container->lamps + i)->plinthType);
    }

    fclose(file);
}

void printStructure(struct LampContainer *container)
{
    for (int i = 0; i < container->size; i++) {
        printf("{%d %d %s %d %d %d %u %u}\n",
               (container->lamps + i)->isTurnedOn,
               (container->lamps + i)->isBroken,
               (container->lamps + i)->manufacturer,
               (container->lamps + i)->leftStarts,
               (container->lamps + i)->wattPerHour,
               (container->lamps + i)->colourTemperature,
               (container->lamps + i)->shape,
               (container->lamps + i)->plinthType);
    }
}

void getBrokenLamps(struct LampContainer *container,
                    struct LampContainer *brokenContainer)
{
    for (int i = 0, j = 0; i < container->size; i++) {
        if ((container->lamps + i)->isBroken == true) {
            append(brokenContainer, (container->lamps + i));
            j++;
        }
    }
}

void sortByField(struct LampContainer *container)
{
    for (int i = 0; i < container->size; i++) {
        for (int j = 1; j < container->size; j++) {
            int prew_val = (container->lamps + j)->leftStarts;
            int curr_val = (container->lamps + j - 1)->leftStarts;

            if (curr_val > prew_val) {
                struct Lamp temp = *(container->lamps + j);

                *(container->lamps + j) = *(container->lamps + j - 1);
                *(container->lamps + j - 1) = temp;
            }
        }
    }
}
