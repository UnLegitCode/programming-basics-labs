#include <stdio.h>
#include "util.h"

int binarySearch(const int* array, const int songAmount, const int controlTime) {
    int left = 0,
        right = songAmount;

    while (left <= right) {
        int middle = left + ((right - left) >> 1);

        if (array[middle] >= controlTime && array[middle - 1] < controlTime) {
            return middle;
        }

        if (array[middle] < controlTime) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return 0;
}

int main() {
    int songAmount, controlTimeAmount;

    scanf("%d %d", &songAmount, &controlTimeAmount);

    int array_times[songAmount + 1];

    array_times[0] = 0;

    for (int i = 0; i < songAmount; i++) {
        array_times[i + 1] = scanInt() * scanInt() + array_times[i];
    }

    for (int i = 0; i < controlTimeAmount; i++) {
        printf("%d\n", binarySearch(array_times, songAmount, scanInt()));
    }
}