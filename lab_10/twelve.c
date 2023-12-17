#include <stdbool.h>
#include <stdio.h>
#include "util.h"

bool binarySearch(const int array[], const int length, const int desiredNumber) {
    int left = 1,
        right = length - 1;

    while (left <= right) {
        int middle = left + ((right - left) >> 1);

        if (array[middle] == desiredNumber) {
            return true;
        }

        if (array[middle] < desiredNumber) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return false;
}

bool checkNum(int array[], const int length, const int desired_number) {
    for (int i = 0; i < length; i++) {
        if (binarySearch(array, length, desired_number - array[i])) {
            return true;
        }
    }

    return false;
}

void fillArray(int array[], const int limit, int *const length) {
    int i = 1;

    while (array[i - 1] + i < limit) {
        array[i] = array[i - 1] + i;
        i++;
    }

    *length = i;
}

int main() {
    int number = scanInt();
    int length;
    int array[100000];

    array[0] = 0;

    fillArray(array, number, &length);

    printf(checkNum(array, length, number) ? "YES" : "NO");
}