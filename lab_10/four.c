#include <stdio.h>
#include "util.h"

int findLower(const int* array, const int size, const int value) {
    int left_bound = -1,
        right_bound = size,
        middle;

    while (left_bound < right_bound - 1) {
        middle = left_bound + ((right_bound - left_bound) >> 1);

        if (array[middle] <= value) {
            left_bound = middle;
        } else {
            right_bound = middle;
        }
    }

    return left_bound;
}

int findUpper(const int* array, const int size, const int value) {
    int left_bound = -1,
        right_bound = size,
        middle;

    while (left_bound < (right_bound - 1)) {
        middle = left_bound + ((right_bound - left_bound) >> 1);

        if (array[middle] >= value) {
            right_bound = middle;
        } else {
            left_bound = middle;
        }
    }

    return right_bound;
}

int getNumbersBetweenBounds(int left_bound, int right_bound, const int size) {
    left_bound += (left_bound == -1);
    right_bound -= (right_bound == size);

    return (right_bound >= left_bound) ? (right_bound - left_bound + 1) : 0;
}

int solveRequest(const int *array, int size, int lower_bound, int upper_bound) {
    return getNumbersBetweenBounds(
            findUpper(array, size, lower_bound),
            findLower(array, size, upper_bound),
            size
    );
}

int main() {
    int arraySize = scanInt();
    int* array = scanNumArray(arraySize);
    int requestAmount = scanInt();

    sortIntArray(array, arraySize);

    for (int i = 0; i < requestAmount; i++) {
        printf("%d ", solveRequest(array, arraySize, scanInt(), scanInt()));
    }
}