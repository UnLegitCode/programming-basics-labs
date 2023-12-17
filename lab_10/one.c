#include <stdio.h>
#include <stdbool.h>
#include "util.h"

bool binarySearch(const int *array, const int size, const int value) {
    int left = 0,
        right = size - 1;

    while (left <= right) {
        const int middle = left + (right - left) / 2;
        const int middleValue = array[middle];

        if (middleValue == value) {
            return true;
        }

        if (middleValue < value) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return false;
}

int main() {
    int arraySize, requestAmount;

    scanf("%d %d", &arraySize, &requestAmount);

    int* array = scanNumArray(arraySize);

    for (int i = 0; i < requestAmount; i++) {
        if (binarySearch(array, arraySize, scanInt())) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}