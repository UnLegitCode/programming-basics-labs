#include <stdio.h>
#include "util.h"

int binarySearch(const int* array, const int size, const int target) {
    int left = 0,
        right = size - 1,
        middle,
        result = -1;

    while (left <= right) {
        middle = (left + right) >> 1;

        if (array[middle] <= target) {
            result = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return result + 1;
}

int main() {
    int arraySize, requestAmount;

    scanf("%d %d", &arraySize, &requestAmount);

    int* array = scanNumArray(arraySize);

    for (int i = 0; i < requestAmount; i++) {
        printf("%d ", binarySearch(array, arraySize, scanInt()));
    }
}