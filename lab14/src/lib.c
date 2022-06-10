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
                  struct Lamp *lamps)
{
    FILE *file = fopen(fileName, "r");
    char line[MAX_STRING_LENGTH];

    for (int i = LAMP_NUMBER - 1; fscanf(file, "%[^\n]", line) != EOF; i--) {
        fgetc(file);
        int tempIsTurnedOn = 1, tempIsBroken = 1;

        sscanf(line, 
               "%d %d %s %d %d %d %u %u",
               &tempIsTurnedOn,
               &tempIsBroken,
               (lamps + i)->manufacturer,
               &(lamps + i)->leftStarts,
               &(lamps + i)->wattPerHour,
               &(lamps + i)->colourTemperature,
               &(lamps + i)->shape,
               &(lamps + i)->plinthType);

        (lamps + i)->isTurnedOn = tempIsTurnedOn;
        (lamps + i)->isBroken = tempIsBroken;
    }
    
    fclose(file);
}

void writeToFile(char *fileName,
                 struct Lamp *lamps)
{
    FILE *file = fopen(fileName, "w");

    for (int i = 0; i < LAMP_NUMBER; i++) {
        fprintf(file, 
                "%d %d %s %d %d %d %d %d\n",
                (lamps + i)->isTurnedOn,
                (lamps + i)->isBroken,
                (lamps + i)->manufacturer,
                (lamps + i)->leftStarts,
                (lamps + i)->wattPerHour,
                (lamps + i)->colourTemperature,
                (lamps + i)->shape,
                (lamps + i)->plinthType);
    }

    fclose(file);
}

void printStructure(struct Lamp *lamps)
{
    for (int i = 0; i < LAMP_NUMBER; i++) {
        printf("{%d %d %s %d %d %d %u %u}\n",
               (lamps + i)->isTurnedOn,
               (lamps + i)->isBroken,
               (lamps + i)->manufacturer,
               (lamps + i)->leftStarts,
               (lamps + i)->wattPerHour,
               (lamps + i)->colourTemperature,
               (lamps + i)->shape,
               (lamps + i)->plinthType);
    }
}

void getBrokenLamps(struct Lamp *lamps,
                    struct Lamp *brokenLamps)
{
    for (int i = 0, j = 0; i < LAMP_NUMBER; i++) {
        if ((lamps + i)->isBroken == true) {
            *(brokenLamps + j) = *(lamps + i);
            j++;
        }
    }
}

void sortByField(struct Lamp *lamps)
{
    for (int i = 0; i < LAMP_NUMBER; i++) {
        for (int j = 1; j < LAMP_NUMBER; j++) {
            int prew_val = (lamps + j)->leftStarts;
            int curr_val = (lamps + j - 1)->leftStarts;

            if (curr_val > prew_val) {
                struct Lamp temp = *(lamps + j);

                *(lamps + j) = *(lamps + j - 1);
                *(lamps + j - 1) = temp;
            }
        }
    }
}
