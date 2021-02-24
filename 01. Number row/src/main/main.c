#include "main.h"
#include <stdio.h>

#define NUMBER_MAX_LENGTH 1000

char isValid(const char number[]) {
    if (number[0] == 0) {
        return 0;
    }

    size_t i;
    for (i = 0; i < NUMBER_MAX_LENGTH && number[i] != 0; ++i) {
        if (number[i] < '0' || number[i] > '9') {
            return 0;
        }
    }

    return 1;
}

int main() {
    printf("Enter a number: ");
    char number[NUMBER_MAX_LENGTH];
    if (scanf("%s", number) != 1 || isValid(number) == 0) {
        printf("Number isn't valid\n");
        return 0;
    }

    char prevNumber = number[0];
    char isOrderedAscending = 1;
    char isOrderedDescending = 1;

    size_t i;
    for (i = 1; i < NUMBER_MAX_LENGTH && number[i] != 0; ++i) {
        if (number[i] < prevNumber) {
            isOrderedAscending = 0;
        }

        if (number[i] > prevNumber) {
            isOrderedDescending = 0;
        }

        prevNumber = number[i];
    }

    if (isOrderedAscending == 1 && isOrderedDescending == 1) {
        printf("All numbers are equal\n");
    } else if (isOrderedAscending == 1) {
        printf("Numbers are ordered ascending\n");
    } else if (isOrderedDescending == 1) {
        printf("Numbers are ordered descending\n");
    } else {
        printf("Numbers aren't ordered ascending nor descending\n");
    }

    return 0;
}
