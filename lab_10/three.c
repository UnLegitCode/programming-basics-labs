#include <stdio.h>
#include "util.h"

int binarySearch(const int* array, const int size, const int value) {
    int left = 0,
        right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] >= value) {
            if (mid == 0 || array[mid - 1] < value) {
                return mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            left = mid + 1;
        }
    }
    return size + 1;
}

int main() {
    int arraySize, requestAmount;

    scanf("%d %d", &arraySize, &requestAmount);

    int* array = scanNumArray(arraySize);

    for (int i = 0; i < requestAmount; i++) {
        printf("%d\n", binarySearch(array, arraySize, scanInt()));
    }
}