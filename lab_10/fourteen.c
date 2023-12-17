#include <stdio.h>
#include <math.h>
#include "util.h"

void fillArray(int array[], const int length) {
    for (int i = 0; i < length; i++) {
        int number = scanInt();

        if (number >= i) {
            array[i] = ceil((double) (number - i) / length);
        } else {
            array[i] = 0;
        }
    }
}

int positionOfMin(const int array[], const int length) {
    int minimum = array[0],
        minimumIndex = 0;

    for (int i = 1; i < length; i++) {
        if (array[i] < minimum) {
            minimum = array[i];
            minimumIndex = i;
        }
    }

    return minimumIndex + 1;
}

int main() {
    int number = scanInt();
    int array[number];

    fillArray(array, number);

    printf("%d", positionOfMin(array, number));
}